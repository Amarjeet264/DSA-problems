class Solution {
    int mod=1e9+7;
    int ways(int start,int end,int steps,vector<vector<int>>&dp){
        if(start>end&&start-end>steps)return 0;
        if(steps==0){
            if(start==end){
                return 1;
            }
            return 0;
        }
        if(steps<0)return 0;
        if(dp[start+1000][steps]!=-1)return dp[start+1000][steps]%mod;
        int left=0;
        left=ways(start+1,end,steps-1,dp)%mod;

        int right=0;
        right=ways(start-1,end,steps-1,dp)%mod;
        
        return dp[start+1000][steps]=(left+right)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(10000,vector<int>(1001,-1));
        return ways(startPos,endPos,k,dp)%mod;
    }
};