class Solution {
public:
    int f(int i, int j ,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j >= matrix[0].size()) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int u = matrix[i][j] + f(i-1,j,matrix,dp);
        int l = matrix[i][j] + f(i-1,j-1,matrix,dp);
        int r = matrix[i][j] + f(i-1,j+1,matrix,dp);

        return dp[i][j]=min(u,min(l,r));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        int mini= INT_MAX;
        for(int j=0;j<m;j++){
            mini=min(mini,f(n-1,j,matrix,dp));
        }
        return mini;
    }
};