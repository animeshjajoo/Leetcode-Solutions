//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool inside(int nx, int ny, int n, int m){
        return (nx>=0 && ny>=0 && nx<n && ny<m);
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }
        
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        q.push({0,source});
        dist[source.first][source.second] = 0;
        
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        
        while(!q.empty()){
            
            int d = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            // traversing neighbours
            for(int i = 0; i<4; i++){
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(inside(nx,ny,n,m) && grid[nx][ny] && d+1 < dist[nx][ny]){
                    
                    // target found
                    if(nx == destination.first && ny == destination.second){
                        return d+1;
                    }
                    
                    // update
                    dist[nx][ny] = d + 1;
                    q.push({d+1,{nx,ny}});
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends