class Solution {
public:

    bool insidegrid(int nx, int ny, int m, int n){
        return (nx>=0 && ny>=0 && nx<m && ny<n);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        // row, col, time
        queue<pair<pair<int,int>,int>> q;

        vector<int> d = {-1,0,1,0,-1};

        // start points
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }

        // bfs
        int time = 0;
        while(!q.empty()){

            int x = q.front().first.first;
            int y = q.front().first.second;

            // time
            int t = q.front().second;
            time = max(time,t);

            q.pop();

            // neighbours
            for(int i = 0; i<=3; i++){

                int nx = x + d[i];
                int ny = y + d[i+1];

                if(insidegrid(nx,ny,m,n) && grid[nx][ny] == 1 && !visited[nx][ny]){
                    q.push({{nx,ny},t+1});
                    grid[nx][ny] = 2;
                    visited[nx][ny] = 1;
                }

            }
        }

        // all oranges not rotten/visited
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }

        return time;

    }
};