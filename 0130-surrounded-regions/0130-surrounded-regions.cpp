class Solution {
public:
    bool insidegrid(int nx, int ny, int m, int n){
            return (nx>=0 && ny>=0 && nx<m && ny<n);
    }

    vector<int> d = {-1,0,1,0,-1};

    void dfs(int x, int y, int m, int n, vector<vector<char>>& board, vector<vector<int>>& visited){

        // node
        visited[x][y] = 1;

        // neighbors
        for(int i = 0; i<4; i++){

            int nx = x + d[i];
            int ny = y + d[i+1];

            if(insidegrid(nx,ny,m,n) && !visited[nx][ny] && board[nx][ny] == 'O'){
                dfs(nx,ny,m,n,board,visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        // O connected to any boundary O cannot be changed
        // dfs on boundary O, not visited will be changed

        // starting points: boundaries
        for(int i = 0; i<m; i++){

            // left boundary
            if(board[i][0] == 'O'){
                dfs(i,0,m,n,board,visited);
            }
            
            // right boundary
            if(board[i][n-1] == 'O'){
                dfs(i,n-1,m,n,board,visited);
            }
        }

        for(int j = 0; j<n; j++){

            // top boundary
            if(board[0][j] == 'O'){
                dfs(0,j,m,n,board,visited);
            }

            // bottom boundary
            if(board[m-1][j] == 'O'){
                dfs(m-1,j,m,n,board,visited);
            }
        }

        // not visited O to be changed
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};