class DSU{
public:

    vector<int> rank;
    vector<int> parent;
    
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int findparent(int node){
        
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = findparent(parent[node]);
    }
    
    void unionedge(int u, int v){
        
        int pu = findparent(u);
        int pv = findparent(v);
        
        // attach to component with greater rank
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }

        else{
            parent[pv] = pu;
            rank[pu] += rank[pv];
        }
        
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        DSU ds(n);

        unordered_map<string,int> mp;

        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){

                string mail = accounts[i][j];

                // mail not found in mapping
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }

                // connect mail/ number components
                else{
                    ds.unionedge(i,mp[mail]);
                }
            }
        }

        // add strings to result
        vector<string> results[n];
        for(auto it: mp){
            string mail = it.first;
            int node = ds.findparent(it.second);

            results[node].push_back(mail);
        }
        
        // convert to desired o/p data structure
        vector<vector<string>> ans;
        for(int i = 0; i<n; i++){

            // empty results
            if(results[i].size() == 0){
                continue;
            }

            sort(results[i].begin(), results[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]); // add name
            for(auto it: results[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};