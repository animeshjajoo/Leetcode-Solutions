//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node, vector<int> &visited, vector<vector<int>>& adj, stack<int> &s){
	    
	    visited[node] = 1;
	    
	    for(auto it: adj[node]){
	        if(!visited[it]){
	            dfs(it,visited,adj,s);
	        }
	    }
	    
	    s.push(node);
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
        vector<int> visited(V,0);
        stack<int> s;
        
        // dfs on adj list
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                dfs(i, visited, adj, s);
            }
        }
        
        // reverse adj list, mark all as unvisited (0)
        vector<vector<int>> adjrev(V);
        for(int i = 0; i<V; i++){
            visited[i] = 0;
            for(auto it: adj[i]){
                adjrev[it].push_back(i);
            }
        }   
        
        // count scc
        int scc = 0;
        
        // dfs stack, no of dfs calls = scc
        while(!s.empty()){
            
            int node = s.top();
            s.pop();
            
            if(!visited[node]){
                scc++;
                dfs(node,visited,adjrev,s);
            }
        }
        
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends