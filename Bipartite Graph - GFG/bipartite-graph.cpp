//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    queue<int> q;
	    vector<int> visited(V,0);
	    
	    for(int i = 0; i<V; i++){
	        if(visited[i] == 0){
	            
	            q.push(i);
        	    visited[i] = 1;
        	    
        	    while(!q.empty()){
        	       int node = q.front();
        	       q.pop();
        	       
        	       for(auto it : adj[node]){
        	           if(visited[it] == 0){
        	               q.push(it);
        	               if(visited[node] == 1) visited[it] = 2;
        	               else visited[it] = 1;
        	           }
        	           
        	           else if(visited[it] == visited[node]){
        	               return false;
        	           }
        	       }
        	    }
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends