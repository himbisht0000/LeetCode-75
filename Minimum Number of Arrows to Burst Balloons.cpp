class Solution {
public:
    static bool compare(const vector<int> a, const vector<int> b)
    {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int arrow = 1;
        int leader = 0 ;
        
        //sort the vector based on first element
        sort(points.begin(),points.end(),compare);
        leader = points[0][1];
       
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] <= leader)
            {
                leader = min(points[i][1], leader);
            }
            else
            {
                arrow++;
                leader = points[i][1];
            }
        }

        return arrow;
    }
};
