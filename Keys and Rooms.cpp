class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int number_of_rooms = rooms.size();
        int rooms_visted = 0;
        vector<bool> visited(rooms.size());
        fill(visited.begin(), visited.end(),false);
        queue<int> q;
        int current;
        visited[0] = true;
        rooms_visted++;
        for(int i = 0; i < rooms[0].size(); i++)
        {
            q.push(rooms[0][i]);
            visited[rooms[0][i]] = true;
            rooms_visted++;
        }
        
        
        while(!q.empty())
        {
            current = q.front();
            q.pop();
            
            for(int i = 0; i < rooms[current].size(); i++)
            {
                if(visited[rooms[current][i]] == true)
                continue;

                q.push(rooms[current][i]);
                visited[rooms[current][i]] = true;
                rooms_visted++;
            }

        }

        if(rooms_visted == number_of_rooms)
        return true;


        return false;
    }
};
