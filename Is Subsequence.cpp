class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i , j;

        for( i=0, j=0 ; i < s.length() ; i++,j++)
        {
            while( j < t.length() && s[i] != t[j])
            {
                j++;
            }

            if( j == t.length() )
            {
                break;
            }
        }

        if( i < s.length())
        {
            return false;
        }

        return true;

    }
};
