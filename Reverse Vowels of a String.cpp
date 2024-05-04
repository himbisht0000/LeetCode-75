class Solution {
public:
    bool is_vowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
            ch == 'u' || 
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' ||
            ch == 'U')
            {
                return true;
            }

        return false;
    }
    string reverseVowels(string s) {

        //using double pointer approach 
        int front = 0 , rear = s.length() - 1;

        while(front < rear)
        {
            while( front < s.length() && !is_vowel(s[front]) )
            {
                front++;
            }
            while( rear > 0 && !is_vowel(s[rear]) )
            {
                rear--;
            }
            //cout<<front<<" "<<rear<<endl;
            if(front < rear)
            {
                swap(s[front],s[rear]);
            }
            front++;
            rear--;

        }
        return s;
    }   
};
