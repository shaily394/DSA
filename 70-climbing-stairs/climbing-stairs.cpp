class Solution{
public:
    int func(int ind ,  vector< int> &dp){
        if(ind == 0) return 1;
        if(ind == 1) return 1;
        if(dp[ind] != -1 ) return dp[ind];
        int left = func(ind - 1 , dp);
        int right = INT_MAX;
        if(ind > 1){
            right = func(ind - 2 , dp);
        }
        return dp [ind] = left + right;
    }
       
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return func(n,dp); 
           
    }
};