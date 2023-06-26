//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool insidegrid(int nx, int ny, int n, int m){
        return (nx>=0 && ny>=0 && nx<n && ny<m);
    }
    
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& visited){

        visited[x][y] = 1;
        
        for(int i = -1; i<=1; i++){
            for(int j = -1; j<=1; j++){
                
                int nx = x + i;
                int ny = y + j;
                
                if(insidegrid(nx,ny,n,m) && grid[nx][ny] == '1' && !visited[nx][ny]){
                    dfs(nx,ny,n,m,grid,visited);
                }
                
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(i,j,n,m,grid,visited);
                    count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends