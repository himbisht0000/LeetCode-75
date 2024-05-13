class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        int same = 0;
        int answer, prev = -1, current;
        for(int i = 0; i < nums.size() ; i++)
        {
            q.push(nums[i]);
        }

        while(k && !q.empty())
        {  
            current = q.top();
            q.pop();
            k--;
        }

        return current;
    }
};
