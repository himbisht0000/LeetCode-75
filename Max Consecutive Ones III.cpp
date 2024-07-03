class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // starting and ending index of window
        int i = 0,j = 0;
        // stores the size of current window
        int ans = 0;
        while(j < nums.size())
        {
             // if current number is zero flip it
            if(nums[j] == 0)
            {
                k--;
            }

            // if we have flips k zeros save the size of window
            if( k == 0)
            {
                ans = max(ans,j - i + 1);
            }

            // if k < 0 that mena we flipped more zeros than k so we need to remove extra zero from left side of window
            if( k < 0)
            {
                 // if removed element from window is zero value of k will increase
                if(nums[i] == 0)
                {
                    k++;
                }
                // reduce the size of window by move starting index towards right
                i++;
            }
            // move to next element in nums array
            j++;
        }

        // conner case when we still have k left but all the zeroes are alredy one
        // in that case j will be one more than the last index hence we should no add zero to it
        if(k > 0)
        {
          ans = max(ans,j - i );
        }
        // TC : O(N) , N is the size of nums array
        return ans;
    }
};
