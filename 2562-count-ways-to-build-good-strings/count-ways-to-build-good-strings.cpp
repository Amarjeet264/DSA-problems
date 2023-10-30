class Solution {
    int mod=1e9+7;
    int good(int low,int high,int zero,int one,int len,vector<int>&dp){
        if(len>high)return 0;
        int z=0;
        int o=0;
        if(dp[len]!=-1)return dp[len];
        if(len+zero<=high&&len+zero>=low)
           z=1+good(low,high,zero,one,len+zero,dp);
        else z=good(low,high,zero,one,len+zero,dp);
        if(len+one<=high&&len+one>=low)o=1+good(low,high,zero,one,len+one,dp);
        else o=good(low,high,zero,one,len+one,dp);
        return dp[len]= (z+o)%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return good(low,high,zero,one,0,dp);
    }
};