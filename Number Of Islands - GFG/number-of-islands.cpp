//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        DSU ds(n*m);
        // row*m + col = node number
        
        int count = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<int> d = {-1,0,1,0,-1};
        
        vector<int> result;
        
        for(auto it : operators){
            
            int row = it[0];
            int col = it[1];
            
            // already visited -> same number of islands
            if(visited[row][col] == 1){
                result.push_back(count);
                continue;
            }
            
            int node = row*m + col;
            
            visited[row][col] = 1;
            count++;
            
            for(int i = 0; i<4; i++){
                
                int nx = row + d[i];
                int ny = col + d[i+1];
                int newnode = nx*m + ny;
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny]){
                    
                    // both part of same islands, but diff parents
                    // counted twice
                    if(ds.findparent(node) != ds.findparent(newnode)){
                        count--;
                        ds.unionedge(node,newnode);
                    }

                }
                
            }
            
            result.push_back(count);
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends