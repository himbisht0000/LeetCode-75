class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        stack<char> temp;
        int i = 0;
        string ans;
        for(i = 0 ; i < s.length(); i++)
        {
            if(s[i] != '*')
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }

        while( !st.empty() )
        {
            temp.push(st.top());
            st.pop();
        }
        
        while( !temp.empty() )
        {
            ans+=temp.top();
            temp.pop();
        }

        return ans;
    }
};
