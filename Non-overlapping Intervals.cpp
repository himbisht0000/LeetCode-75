class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) 
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        // sort the vector based on second element
        sort(intervals.begin(), intervals.end(), compare);
        int ans = 0 ;
        int last = intervals[0][1];
        for(int i = 0; i < intervals.size() ;i++)
        {
            if(i == 0)
            continue;

            if(last > intervals[i][0])
            {
                ans++;
            }
            else
            {
                last = intervals[i][1];
            }
        }

        return ans;

    }
};
