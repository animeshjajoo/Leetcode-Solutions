//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int start, int parent, vector<int> adj[], int visited[]){
        
        // starting node
        visited[start] = 1;
        
        // dfs
        for(auto it: adj[start]){
            
            if(!visited[it]){
                if(check(it,start,adj,visited)){
                    return true;
                }
            }
            
            else if(it != parent){
                return true;
            }
                
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        int visited[V] = {0};
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                bool test = check(i,-1,adj,visited);
                if(test){
                    return true;
                    break;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends