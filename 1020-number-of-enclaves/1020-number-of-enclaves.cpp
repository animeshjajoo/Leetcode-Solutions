class Solution {
public:

    bool insidegrid(int nx, int ny, int m, int n){
        return (nx>=0 && ny>=0 && nx<m && ny<n);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        vector<int> d = {-1,0,1,0,-1};

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {

                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    if(grid[i][j]) {
                        q.push({i, j}); 
                        visited[i][j] = 1; 
                    }
                }

            }
        }

        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){

                int nx = x + d[i];
                int ny = y + d[i+1];

                if(insidegrid(nx,ny,m,n) && visited[nx][ny]==0 && grid[nx][ny]==1){
                    q.push({nx,ny});
                    visited[nx][ny] = 1;
                }
            }
        }

        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(visited[i][j]==0 && grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};