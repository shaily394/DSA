class Solution {
public:
    int f(int ind,int prev_ind,vector<int> &nums ,  vector<vector<int>> &dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        int nottake= 0+f(ind+1 , prev_ind ,nums,dp);
        int take =0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            take = 1+ f(ind+1,ind,nums,dp);
        }
        return dp[ind][prev_ind+1]=max(nottake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1)); //coordinate change for prev_ind
        return f(0,-1,nums,dp);
    }
};