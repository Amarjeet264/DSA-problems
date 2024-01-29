class Solution {
    

public:
    int findMinFibonacciNumbers(int k) {
        vector<int>dp(100,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=45;i++){
            dp[i]=dp[i-1]+dp[i-2];
            // cout<<dp[i]<<" ";
        }
        int cnt=0;
        for(int i=45;i>=0;i--){
            if(k>=dp[i]){
                int x=k/dp[i];
                k-=x*dp[i];
                cnt+=x;
            }
            if(k==0){
                return cnt;
            }
        }
        return -1;
    }
};