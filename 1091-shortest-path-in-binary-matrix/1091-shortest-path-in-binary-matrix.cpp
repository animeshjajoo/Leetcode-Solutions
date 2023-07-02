class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0]) return -1;
        if(n == 1) return 1;

        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;

        q.push({1,{0,0}});
        dist[0][0] = 0;

        while(!q.empty()){

            int d = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    int nx = x+i;
                    int ny = y+j;

                    if(nx>=0 && ny>=0 && nx<n && ny<n && !grid[nx][ny] 
                    && d+1<dist[nx][ny]){

                        if(nx == n-1 && ny == n-1){
                            return d+1;
                        }

                        dist[nx][ny] = d+1;
                        q.push({d+1,{nx,ny}});
                    }
                }
            }
        }

        return -1;
    }
};