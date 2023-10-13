class Solution {
    int pro(int k,vector<int>&prices,int buy,int i,vector<vector<vector<int>>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        if(k==0){
            return 0;
        }
        if(buy){
            return dp[i][buy][k]= max(-prices[i]+pro(k,prices,0,i+1,dp),pro(k,prices,1,i+1,dp));
        }
        return dp[i][buy][k]= max(prices[i]+pro(k-1,prices,1,i+1,dp),pro(k,prices,0,i+1,dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return pro(k,prices,1,0,dp);
    }
};