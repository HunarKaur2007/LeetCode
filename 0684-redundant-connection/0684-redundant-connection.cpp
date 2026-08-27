class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>&adj, vector<int>& vis){
        vis[node]=1;
        for(int i=0;i<adj[node].size();i++){
            int neighbour = adj[node][i];
            if(vis[neighbour] == 0){
                if(dfs(neighbour, node, adj, vis)) return true;}
                else if (neighbour != parent) return true;
            
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u =edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<int> vis(n+1,0);
            if(dfs(u,-1,adj,vis)){
                return edges[i];
            }
        }
        return {};
    }
};