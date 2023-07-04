class DSU{
public:

    vector<int> rank;
    vector<int> parent;
    
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int findparent(int node){
        
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = findparent(parent[node]);
    }
    
    void unionedge(int u, int v){
        
        int pu = findparent(u);
        int pv = findparent(v);
        
        // attach to component with greater rank
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        
        // equal rank
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
        
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DSU ds(n);
        int extraedges = 0;

        for(auto it: connections){

            int u = it[0];
            int v = it[1];

            // same parent -> same component -> extra edge
            if(ds.findparent(u) == ds.findparent(v)){
                extraedges++;
            }
            
            else{
                ds.unionedge(u,v);
            }
        }

        // connected components
        int noc = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i] == i){
                noc++;
            }
        }

        // noc components need noc-1 edges to connect
        // if extra edges equal or more to noc-1, graph can connect

        if(extraedges >= noc-1){
            return noc-1;
        }

        return -1;
    }
};