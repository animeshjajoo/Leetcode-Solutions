class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjlist(n);
        vector<int> indegree(n);

        for(auto it:prerequisites){
            adjlist[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        vector<int> result;

        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            result.push_back(node);
            q.pop();

            for(auto it: adjlist[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }

        }

        return result.size() == n;
        
    }
};