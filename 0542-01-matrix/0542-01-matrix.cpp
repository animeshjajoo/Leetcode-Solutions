class Solution {
public:
    bool insidegrid(int nx, int ny, int m, int n){
            return (nx>=0 && ny>=0 && nx<m && ny<n);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }

        vector<int> delta = {-1,0,1,0,-1};
        while(!q.empty()){

            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;

            dist[x][y] = d;

            q.pop();

            for(int i = 0; i<4; i++){

                int nx = x + delta[i];
                int ny = y + delta[i+1];

                if(insidegrid(nx,ny,m,n) && !visited[nx][ny]){
                    q.push({{nx,ny},d+1});
                    visited[nx][ny] = 1;
                }
            }
        }

        return dist;
    }
};