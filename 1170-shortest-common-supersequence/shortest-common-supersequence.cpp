class Solution {
public:
     int f(int i , int j, string &s, string &t , vector<vector<int>> &dp){
        if(i==0 || j==00) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        if(s[i-1] == t[j-1]) return dp[i][j] = 1+ f(i-1,j-1,s,t,dp);
        return dp[i][j] =0+ max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        f(n,m,str1,str2,dp);
        string ans ="";
        int i = n,j=m;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i-- ,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans += str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }
        reverse (ans.begin() , ans.end());
        return ans;
    }
};