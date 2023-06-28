//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> d = {-1,0,1,0,-1};
    
    bool inside(int nx, int ny, int n, int m){
        return (nx>=0 && ny>=0 && nx<n && ny<m);
    }
  
    void dfs(int x, int y, int x0, int y0, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int,int>>& vec){
        
        int n = grid.size();
        int m = grid[0].size();
        
        visited[x][y] = 1;
        vec.push_back({x-x0,y-y0});
        
        for(int i = 0; i<4; i++){
            int nx = x + d[i];
            int ny = y + d[i+1];
            
            if(inside(nx,ny,n,m) && !visited[nx][ny] && grid[nx][ny]){
                dfs(nx,ny,x0,y0,grid,visited,vec);
            }
        }
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j]){
                    vector<pair<int,int>> vec;
                    dfs(i,j,i,j,grid,visited,vec);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends