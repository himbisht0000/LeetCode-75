class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // store the cost incurred to reach for each cell size is one more which represent the 
        // top
        vector<int> path(cost.size() + 1); 
        fill(path.begin(), path.end(),0);
        int min_cost = 0;
        int i;
        for(i = 2 ; i < path.size(); i++)
        {
            // check last and second last elemnt for current value
            min_cost = min( path[i-1] + cost[i-1], path[i-2] + cost[i-2]);
            path[i] = min_cost;
        }

        return path[i-1];// return last value 
    }
};
