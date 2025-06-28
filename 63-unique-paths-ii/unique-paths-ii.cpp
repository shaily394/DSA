class Solution {
public:
    int f(int i, int j, vector<vector<int>> &og ,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up =0 ,left =0;
        if(i>0 && og[i-1][j] ==0) up= f(i-1,j,og,dp); //check for ou of bound indices . it gives runtime error.
        if(j>0 && og[i][j-1]==0) left = f(i,j-1,og,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m =obstacleGrid.size();
        int n =obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        return f(m-1,n-1 , obstacleGrid,dp);
    }
};