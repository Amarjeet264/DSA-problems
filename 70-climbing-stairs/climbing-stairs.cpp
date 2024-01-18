class Solution {
    
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1;
        if(n<=1)return 1;
        for(int i=1;i<=n;i++){
           int left=0;
           int left2=0;
           if(i-1>=0){
               left=dp[i-1];
           }
           if(i-2>=0){
               left2=dp[i-2];
           }
           dp[i]=left+left2;
        }
        return dp[n];
    }
};