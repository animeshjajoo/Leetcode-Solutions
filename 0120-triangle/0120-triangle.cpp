class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp){

        if(i == a.size()-1) return a[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = a[i][j] + fun(i+1,j,a,dp);
        int dia = a[i][j] + fun(i+1,j+1,a,dp);

        return dp[i][j] = min(down,dia);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), 
        vector<int>(triangle[triangle.size()-1].size(),-1));
        return fun(0,0,triangle,dp);
    }
};