class Solution {
public:
    int reverse_freq(vector<int> freq)
    {
        int ans = 0;
        int i = freq.size() - 1;
        for( ; i>=0 ; i--)
        {
            ans = ans * 10 + freq[i] - '0';
        }
        return ans;
    }
    string decodeString(string s) {
        stack<char> st;
        vector<int> freq;
        string word;
        string ans;
        int i = 0;
        while(i < s.length())
        {
            if(s[i] != ']')
            {
                st.push(s[i]);
            }
            else // process the enclosed bracket
            {
                while(st.top() != '[')
                {
                    word+=st.top();
                    st.pop();
                }
                st.pop();
                //reverse the word
                reverse(word.begin(),word.end());
                //cout<<"word "<<word<<endl;
                //find the frequency
                while( (!st.empty()) && st.top() >='0' && st.top() <= '9')
                {
                    freq.push_back(st.top());
                    st.pop();
                }
                // using vector to handle case when freq is 1000
                int count = 0;
                count = reverse_freq(freq);
                //cout<<"freq "<<freq<<endl;
                // expand the word using frequency
                while(count)
                {
                    count--;
                    for(int i = 0;i<word.length();i++)
                    {
                        st.push(word[i]);
                    }
                }

            }

            word.erase();
            freq.clear();
            i++;

        }

        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};
