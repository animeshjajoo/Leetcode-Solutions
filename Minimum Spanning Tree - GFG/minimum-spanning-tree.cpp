//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class DSU
{
    vector<int> rank;
    vector<int> parent;
    
    public:
    
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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0; i<V; i++){
            for(auto it: adj[i]){
                edges.push_back({it[1],{it[0], i}});
            }
        }
        
        // sort edges (min edge weight first)
        sort(edges.begin(), edges.end());
        
        int sum = 0;
        DSU ds(V);
        
        for(auto it: edges){
            
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            // diff component -> add to mst
            if(ds.findparent(u) != ds.findparent(v)){
                ds.unionedge(u,v);
                sum += wt;
            }
            
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends