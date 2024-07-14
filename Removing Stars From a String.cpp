class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        
        int i = 0;
        string output;
        
        // traverse the string and remove star along with its left character
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

        // store remainning character in output
        while( !st.empty() )
        {
            output+=st.top();
            st.pop();
        }

        //reverse the string to get correct output
        reverse(output.begin(), output.end());

        //Tc: O(N) :  N is the size of input string
        return output;
    }
};
