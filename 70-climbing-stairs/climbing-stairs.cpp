class Solution{
public:
    
       
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            int left = dp[i - 1];
            int right = INT_MAX;
            if(i> 1){
                right = dp[i- 2];
            }
            dp [i] = left + right;
        }
        return dp[n]; 
           
    }
};