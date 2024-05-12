class Solution {
public:

    void DFS(int source, vector<vector<int>>& isConnected, vector<bool> &visited)
    {
        stack<int> st;
        int s;
        st.push(source);
        while(!st.empty())
        {
            s = st.top();
            visited[s] = true;
            st.pop();

            for(int i = 0 ; i < isConnected[s].size(); i++)
            {
                if(visited[i] == false && isConnected[s][i] )
                {
                    st.push(i);
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int count = 0;
        fill(visited.begin(), visited.end(),false);

        for(int i = 0 ; i < isConnected.size(); i++)
        {
            if(visited[i] == false)
            {
                
                DFS(i , isConnected, visited);
                count++;
            }
        }

        return count;
    }
};
