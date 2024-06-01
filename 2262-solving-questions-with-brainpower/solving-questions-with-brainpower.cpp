class Solution {
public:
    long long mostPoints(vector<vector<int>>& que) {
        int n=que.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int nxtidx=i+que[i][1]+1;
            if(nxtidx<n){
                dp[i]=max((long long)dp[i+1],(long long)que[i][0]+dp[nxtidx]);
            }
            else{
                if(i+1<n){
                    dp[i]=max(dp[i+1],(long long)que[i][0]);
                }
                else dp[i]=(long long)que[i][0];
            }
        }
        return dp[0];
    }
};