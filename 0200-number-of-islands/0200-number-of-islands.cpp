class Solution {
public:

    // function to visited all land on an island and mark them as visited
    void dfs(int x, int y,vector<vector<int>> &visited, vector<vector<char>> &grid,vector<int> &dx,vector<int> &dy, int n, int m){

        // mark cell as visited
        visited[x][y] = 1;

        // visit neighbour cells
        for(int i = 0; i<4; i++){

            int nx = x + dx[i];
            int ny = y + dy[i];

            // check for unvisited valid cells
            if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0 
            &&grid[nx][ny]=='1'){

                // recursive call to visited
                dfs(nx,ny,visited,grid,dx,dy,n,m);
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        // passed dx dy in dfs to reduce space + time
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};

        vector<vector<int>> visited(n,vector<int>(m,0));

        // traverse grid
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                
                // if unvisited and vaild -> island hai
                // number of bfs/dfs traversals = count
                if(!visited[i][j] && grid[i][j]=='1'){

                    // increase count
                    count++;

                    // dfs call to visit cell and its valid (land) neighbours
                    dfs(i,j,visited,grid,dx,dy,n,m);
                }
            }
        }

        return count;
        
    }
};