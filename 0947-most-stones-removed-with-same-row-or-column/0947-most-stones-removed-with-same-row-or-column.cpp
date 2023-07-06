class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {

        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

    }

    int findUPar(int node) {

        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }

        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }

        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

    }

    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();

        // finding size of grid
        int maxrow = 0, maxcol = 0;
        for(auto it:stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }

        DisjointSet ds(maxrow+maxcol+1);
        vector<int> visited(maxrow+maxcol+2, 0);

        // creating components
        for(auto it:stones){

            int row = it[0];
            int col = it[1] + maxrow+1;

            visited[row] = 1;
            visited[col] = 1;

            if(ds.findUPar(row) != ds.findUPar(col)){
                ds.unionBySize(row,col);
            }

        }

        // stones that cannot be removed -> have same parent
        unordered_set<int> st;
        for(int i = 0; i<visited.size(); i++){
            if(visited[i]){
                st.insert(ds.findUPar(i));
            }
        }

        return stones.size() - st.size();

    }
};