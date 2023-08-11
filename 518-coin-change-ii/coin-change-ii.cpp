class Solution {
    int coinss(int target,int i,vector<int>&coins,vector<vector<int>>&dp){
        if(target==0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int nottake=coinss(target,i-1,coins,dp);
        int take=0;
        if(target>=coins[i]){
            take=coinss(target-coins[i],i,coins,dp);
        }
        return dp[i][target]= take+nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return coinss(amount,coins.size()-1,coins,dp);
    }
};