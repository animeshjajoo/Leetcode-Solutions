class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        queue<pair<int,int>> q;
        q.push({sr,sc});

        int old = image[sr][sc];
        
        vector<int> d = {-1,0,1,0,-1};

        // bfs traversal
        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;

            // mark visited, recolor cell
            visited[x][y] = 1;
            image[x][y] = color;

            q.pop();

            for(int i = 0; i<4; i++){

                int nx = x + d[i];
                int ny = y + d[i+1];

                // if new point inside grid, not visited, has old color
                if(insidegrid(nx,ny,m,n) && image[nx][ny] == old 
                && !visited[nx][ny]){
                    q.push({nx,ny});
                }
                
            }

        }

        return image;
    }

    bool insidegrid(int nx, int ny, int m, int n){
        return (nx>=0 && ny>=0 && nx<m && ny<n);
    }
    
};