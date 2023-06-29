class Solution {
public:

    bool dfs(vector<vector<int>> &adjlist,vector<int> &safe,vector<int> &path,vector<int> &visited,int node){

        // mark visited and path
        visited[node] = 1;
        path[node] = 1;

        // traverse neighbours in adj list
        for(auto i:adjlist[node]){
            
            // if unvisited and not on the same path
            if(visited[i]==0 && path[i] == 0){

                // if dfs is true, then unsafe
                if(dfs(adjlist,safe,path,visited,i) == true){
                    return true;
                }
            }

            // if visited and on the same path
            // unsafe
            else if(visited[i] == 1 && path[i]==1){
                return true;
            }
        }

        // unmark path visited for dfs
        path[node] = 0;

        // mark node as safe
        safe[node] = 1;

        return false;

    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        // adj list
        vector<vector<int>> adjlist(n);
        for(int i = 0; i<graph.size(); i++){
            for(int j = 0; j<graph[i].size(); j++){
                adjlist[i].push_back(graph[i][j]);
            }
        }

        vector<int> safe(n,0);
        vector<int> path(n,0);
        vector<int> visited(n,0);
        

        // dfs for all nodes
        for(int i = 0; i<n; i++){
            if(visited[i]==0){
                dfs(adjlist,safe,path,visited,i);
            }
        }

        // store safe states in result
        vector<int> result;
        for(int i = 0; i<n; i++){
            if(safe[i]==1){
                result.push_back(i);
            }
        }

        return result;

    }
};