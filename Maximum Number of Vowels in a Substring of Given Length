class Solution {
public:
    int is_vowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return 1;
        }

        return 0;
    }
    int maxVowels(string s, int k) {
        //left most and right most index of the sliding window
        int left = 0,right = k-1;
        // maximum number of vowels seen till now
        int max_count = 0;
        //current count of vowel
        int count = 0;

        //find the initial number of vowel in the window befor sliding
        for(int i=0; i < k ;i++ )
        {
            if( is_vowel(s[i]) )
            {
                max_count++;
            }
        }
        count = max_count;
        //slide the window by one element
        left++;
        right++;

        // now slide the window and check in remainning array for maximum vowel
        while(right < s.length())
        {
            count = count - is_vowel(s[left - 1]) + is_vowel(s[right]);
            max_count = max(max_count,count);
            left++;
            right++;
        }

        return max_count;
    }
};
