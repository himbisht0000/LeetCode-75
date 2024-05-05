class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int prefix_sum = 0;
        for(int i = 0; i < nums.size() ; i++)
        {
            sum+=nums[i];
        }

        for(int i = 0; i < nums.size() ; i++)
        {
            if(prefix_sum == (sum - nums[i] - prefix_sum) )
            {
                return i;
            }
            else
            {
                prefix_sum += nums[i];
            }
        }

        return -1;

    }
};
