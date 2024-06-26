
class Solution {
public:
    int guessNumber(int n) {
        int left = 1 , right = n;
        int mid ;

        while(left < right)
        {
            // to avoid int overflow
            mid = left + ( right - left)/2;
            if(guess(mid) == -1){
                right = mid - 1;
            }
            else if(guess(mid) == 1)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return left;
    }
};
