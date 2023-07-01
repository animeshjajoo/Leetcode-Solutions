//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int> adj[N]; // adj list
        for(int i = 0; i<M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> dist(N,1e9);
        queue<int> q;
        
        // source
        q.push(src);
        dist[src] = 0;
        
        // bfs
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto it:adj[node]){
                
                // update node
                if(dist[node]+1 < dist[it]){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        for(int i = 0; i<N; i++){
            if(dist[i]==1e9) dist[i] = -1;
        }
        
        return dist;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends