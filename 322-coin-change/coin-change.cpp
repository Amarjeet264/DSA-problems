class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e9);
        for(int tar=0;tar<=amount;tar++){
            if(tar==0){
                dp[tar]=0;
                continue;
            }
            for(int i=0;i<coins.size();i++){
                if(tar>=coins[i]){
                    dp[tar]=min(dp[tar],1+dp[tar-coins[i]]);
                }
            }
        }
        if(dp[amount]==1e9){
            return -1;
        }
        return dp[amount];
    }
};