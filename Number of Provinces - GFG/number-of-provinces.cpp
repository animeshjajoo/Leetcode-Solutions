//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DSU
{
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
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        DSU ds(V);
        
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(adj[i][j]){
                    ds.unionedge(i,j);
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i<V; i++){
            if(ds.parent[i] == i){
                count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends