//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node, vector<pair<int,int>> adj[], vector<int> &visited, stack<int>&s){
         
         visited[node] = 1;
         
         for(auto it: adj[node]){
             if(!visited[it.first]){
                 dfs(it.first,adj,visited,s);
             }
         }
         
         s.push(node);
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        // adj list
        vector<pair<int,int>> adj[N];
        for(int i = 0; i<M; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int> visited(N,0);
        stack<int> s;
        
        // dfs
        for(int i = 0; i<N; i++){
            if(!visited[i]){
                dfs(i,adj,visited,s);
            }
        }
        
        // relax edges
        vector<int> dist(N,1e9);
        
        // source node
        dist[0] = 0;
        
        while(!s.empty()){
            
            int node = s.top();
            s.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        // impossible to reach vertex
        for(int i = 0; i<N; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends