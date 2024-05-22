class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int grid[m][n];
        memset(grid,0,sizeof(int) * m * n);
        //first row and colunm will have all the value to be 1
        // As their is only one way to reach the end cell if there is one column or one row
        for(int i = 0; i < n ; i++)
        {
            grid[0][i] = 1;
        }

        for(int i = 0; i < m ; i++)
        {
            grid[i][0] = 1;
        }

        for(int i = 1; i < m ; i++)
        {
            for(int j = 1; j < n; j++)
            {
                grid[i][j] = grid[i][j-1] + grid[i-1][j]; 
            }
        }

        return grid[m-1][n-1];

    }
};
