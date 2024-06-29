class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // left and right pointer 
        int left = 0,right = nums.size() - 1;
        int operation_count = 0;
        int sum = 0;
        //sort the vector TC : O(nlogn)
        sort(nums.begin(),nums.end());
        
        //left and right will move toward center 
        //TC : O(n)
        while(left < right)
        {
            sum = nums[left] + nums[right];
            //if sum of element at left and right are same then increase 
            //move both left and right pointer towards centre
            if( sum == k)
            {
                operation_count ++;
                left ++;
                right --;
            }
            else if( sum > k)  
            {
                // if sum of left and right is more then move right towards centre
                right--;
            }
            else
            {
                // if sum of left and right is more then move left towards centre
                left ++;
            }
        }

        //return the operation count 
        //Algo TC : O(nlogn)
        return operation_count;

    }
};
