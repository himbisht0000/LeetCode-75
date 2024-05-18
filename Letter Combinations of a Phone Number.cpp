class Solution {
public:
    
    void solve(vector<string> keypad , string digits, vector<string>& ans, string pattern)
    {
        if(digits == "")
        {
            ans.push_back(pattern);
            return;
        }

        for(int i = 0; i < keypad[digits[0] - '0'].length(); i ++)
        {
            solve( keypad, digits.substr(1,digits.length() - 1), ans , pattern + keypad[digits[0] - '0'][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> keypad(10);
        if(digits == "")
        {
            return ans;
        }
        keypad[2] = "abc";
        keypad[3] = "def";
        keypad[4] = "ghi";
        keypad[5] = "jkl";
        keypad[6] = "mno";
        keypad[7] = "pqrs";
        keypad[8] = "tuv";
        keypad[9] = "wxyz";

        solve(keypad, digits,ans,"");
        return ans;
    }
};
