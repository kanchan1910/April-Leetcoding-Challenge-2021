// problem on bridges
// tarjan's algorithm 
class Solution {
public:
    void dfs(vector<int>adj[], vector<int>&dis,vector<int>&low, vector<pair<int, int>>&bridges, int source, int parent)
    {
        static int timer = 1;
        dis[source] = low[source] = timer;
        timer++;
        for(auto child: adj[source])
        {
            // tree edge
            if(dis[child] == -1)
            {
                dfs(adj, dis, low, bridges, child, source);
                // while returning , as if child can reach then parent can also reach
                low[source] = min(low[source], low[child]);
                // checking if bridge exists or not
                if(low[child] > dis[source])
                {
                    bridges.push_back({source, child});
                }
            }
            // back edge
            else
            {
                // no possibility of finding bridge
                // just update
                if(parent != child)
                {
                 low[source] = min(low[source], dis[child]);    
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        //adjacency list
        vector<int>adj[n];
        for(int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        // discovery time
        vector<int>dis(n, -1);
        // low time
        vector<int>low(n, -1);
        // final answer vector
        vector<vector<int>>ans;
        // bridges
        vector<pair<int,int>>bridges;
        for(int i = 0; i < n; i++)
        {
            if(dis[i] == -1)
            {
                dfs(adj, dis, low, bridges, i, -1);
            }
        }
        for(auto x: bridges)
        {
            ans.push_back({x.first, x.second});
        }
        return ans;
    }
};
