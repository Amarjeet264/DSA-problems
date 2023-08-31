class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+2,1e8);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            for(int j=max(i-ranges[i],0);j<=min(i+ranges[i],n);j++){
                dp[j]=min(dp[j],1+dp[max(0,i-ranges[i])]);
            }
        }
        return dp[n]>=1e8?-1:dp[n];
    }
};