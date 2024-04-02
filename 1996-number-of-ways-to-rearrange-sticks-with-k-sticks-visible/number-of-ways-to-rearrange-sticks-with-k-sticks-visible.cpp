class Solution {
    int mod=1e9+7;
    int dp[1005][1005];
    long long rearrange(int n,int k){
        if(n==0){
            return k==0;
        }
        if(k<0)return 0;
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        long long ans=rearrange(n-1,k-1)+((n-1)*rearrange(n-1,k)%mod);
        ans=ans%mod;
        return dp[n][k]= ans;
    }
public:
    int rearrangeSticks(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return rearrange(n,k);
    }
};