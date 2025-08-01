class Solution{
    public:

        int f(int n, vector<int> &dp){
            if(n <= 2) return n;
            if(dp[n] != -1) return dp[n];

            int left = f(n-1, dp);
            int right = f(n-2, dp);
            return dp[n] = left + right;


    }
        int climbStairs(int n) {
                
            vector<int> dp(n+1, -1);
            return f(n, dp);
                }
};