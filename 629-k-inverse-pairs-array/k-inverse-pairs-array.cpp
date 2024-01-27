class Solution {
    int mod=1e9+7;
    int dp[1001][1001];
    int func(int n,int k){
        if(k<0){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=func(n-1,k-i);
            ans%=mod;
        }
        return dp[n][k]=ans;
    }
public:
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        // vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return func(n,k);
    }
};