class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        int count = 0;
        // count the frequency of each row
        for(int i = 0; i < grid.size(); i++)
        {
            if(mp.find(grid[i]) == mp.end())
            mp[grid[i]] = 1;
            else
            mp[grid[i]]++;
        }

        vector<int> col(grid.size());

        for(int i = 0; i < grid[0].size();i++)
        {
            for(int j = 0; j < grid.size();j++)
            {
                col[j] = grid[j][i];
            }
            if(mp.find(col) != mp.end())
            count += mp[col];
        }

        return count;

    }
};
