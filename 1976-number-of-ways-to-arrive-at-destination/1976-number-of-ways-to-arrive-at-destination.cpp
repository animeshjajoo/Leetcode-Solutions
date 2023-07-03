class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = (int)(1e9 + 7);

        vector<vector<pair<long long,long long>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // number of shortest paths
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, 
        greater<pair<long long,long long>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> paths(n,0);

        pq.push({0,0});
        dist[0] = 0;
        paths[0] = 1;

        while(!pq.empty()){

            long long d = pq.top().first;
            long long x = pq.top().second;
            pq.pop();

            for(auto it: adj[x]){

                long long node = it.first;
                long long wt = it.second;

                // first time
                if(d + wt < dist[node]){
                    dist[node] = d+wt;
                    pq.push({d+wt,node});
                    paths[node] = paths[x];
                }

                // prev accessed with shortest dist
                else if(d+wt == dist[node]){
                    paths[node] = (paths[node] + paths[x])%mod;
                }
            }
        }

        return paths[n-1]%mod;
    }
};