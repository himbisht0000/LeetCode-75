class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //Queue to run BFS 
        queue< pair < pair<int,int>,int > > q;
        pair<pair<int,int>,int> source;
        int row,col;
        int m = maze.size(); // maze row
        int n = maze[0].size(); // maze column
        
        //create source 
        source.first.first = entrance[0];
        source.first.second = entrance[1];
        source.second = 0;

        //vector to store directions
        vector<pair<int,int>> direction;
        direction.push_back(make_pair(0,-1)); // left
        direction.push_back(make_pair(-1,0)); // top
        direction.push_back(make_pair(0,1)); // right
        direction.push_back(make_pair(1,0)); // bottom

        //push source in queue
        q.push(source);
        maze[entrance[0]][entrance[1]] = '+';

        while( !q.empty() )
        {
            pair<pair<int,int>,int> current;
            int r,c;
            //fetch current node from front
            current = q.front();
            q.pop();
            //store row and column value of current node
            r = current.first.first;
            c = current.first.second;

            //check if we reached border or not
            if( ( r == 0 || c == 0 || r == (m-1) || c == (n-1) )&& current.second != 0)
            {
                // return the current distance 
                return current.second;
            }

            // visit the blocks in 4 direction
            for(int i = 0; i < 4 ; i++)
            {
                row = r + direction[i].first;
                col = c + direction[i].second;

                if(row >= 0 && row < m && col >=0 && col < n && maze[row][col] == '.' )
                {
                    q.push(make_pair(make_pair(row,col),current.second + 1));
                    //mark this cell as visited
                    maze[row][col] = '+';
                }
            }
    
        }

        return -1;
        
    }
};
