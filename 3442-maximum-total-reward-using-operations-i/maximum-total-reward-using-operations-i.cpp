class Solution {
    int rew(int i,int sum,vector<int>&reward,vector<vector<int>>&dp){
        if(i>=reward.size()){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int nottake=rew(i+1,sum,reward,dp);
        int take=-1e8;
        if(reward[i]>sum){
            take=reward[i]+rew(i+1,sum+reward[i],reward,dp);
        }
        return dp[i][sum]= max(take,nottake);
    }
public:
    int maxTotalReward(vector<int>& reward) {
        sort(reward.begin(),reward.end());
        vector<vector<int>>dp(reward.size(),vector<int>(4000,-1));
        return rew(0,0,reward,dp);
    }
};