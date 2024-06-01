class Solution {
    int call(vector<int>&stones,int i,int j,vector<vector<int>>&dp){
        if(i+1>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int front=0;
        front=min(stones[i+1]+call(stones,i+2,j,dp),stones[j]+call(stones,i+1,j-1,dp));
        int back=0;
        back=min(stones[j-1]+call(stones,i,j-2,dp),stones[i]+call(stones,i+1,j-1,dp));
        return dp[i][j]= max(front,back);
    }
public:
    int stoneGameVII(vector<int>& stones) {
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        return call(stones,0,stones.size()-1,dp);
    }
};