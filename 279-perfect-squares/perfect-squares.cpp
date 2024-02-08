class Solution {
    int nums(int n,vector<int>&dp){
        if(dp[n]!=-1)return dp[n];
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+nums(n-(i*i),dp));
        }
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return nums(n,dp);
    }
};