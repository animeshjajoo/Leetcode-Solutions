class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>> &graph, vector<int> &visited){
        
        visited[node] = col;
        for(auto it: graph[node]){

            if(visited[it] == -1){
                if(dfs(it,!col,graph,visited) == false) return false;
            }
            // not bipartite, already coloured with same color 
            else if(visited[it] == col){
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n,-1);

        for(int i = 0; i<n; i++){
            if(visited[i] == -1){
                if(dfs(i,0,graph,visited) == false){
                    return false;
                }
            }
        }

        return true;
    }
};