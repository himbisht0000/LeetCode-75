class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj_matrix(connections.size() + 1);
        vector<bool> visited(connections.size() + 1);
        int source;
        int count = 0;
        stack<int> st;

        fill(visited.begin(),visited.end(),false);
        //create a adjacency matrix auch that we assume tree to be undirected
        for(int i = 0; i < connections.size() ; i++)
        {
            adj_matrix[connections[i][0]].push_back(make_pair(connections[i][1] , 1));
            adj_matrix[connections[i][1]].push_back(make_pair(connections[i][0] , 0));
        }
        st.push(0);
        visited[source] =true;
        while(!st.empty())
        {   
            
            source = st.top();
            st.pop();
            for(int i = 0 ; i < adj_matrix[source].size(); i++ )
            {
                if(visited[adj_matrix[source][i].first] == false)
                {
                    visited[adj_matrix[source][i].first] = true;
                    st.push(adj_matrix[source][i].first);

                    if(adj_matrix[source][i].second == 1)
                    {
                        count++;
                    }

                }
            }
        }

        return count;

    }
};
