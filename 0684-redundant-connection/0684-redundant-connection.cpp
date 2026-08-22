class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size();
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }//make every node its own parent
        for(auto edge : edges){
            //extract 2 nodes
            int u= edge[0];
            int v= edge[1];
            //find thier roots
            int pu=find(u);
            int pv=find(v);
            //if pu = pv that means u and v are already connected, adding this edge would create a cycle thus its redundant edge
            if(pu==pv) return edge; //same grp = cycle
            //merge 2 grps if grps different
            parent[pu] = pv;
        }
        return {};
    }
};