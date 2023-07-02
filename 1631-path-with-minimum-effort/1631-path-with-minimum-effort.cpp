class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int d[] = {-1,0,1,0,-1};

        while(!pq.empty()){

            int dt = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return dt;

            for(int i = 0; i<4; i++){

                int nx = x+d[i];
                int ny = y+d[i+1];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    int effort = max(dt,abs(heights[x][y] - heights[nx][ny]));
                    if(effort < dist[nx][ny]){
                        dist[nx][ny] = effort;
                        pq.push({effort,{nx,ny}});
                    }
                }
            }
        }

        return 0;
    }
};