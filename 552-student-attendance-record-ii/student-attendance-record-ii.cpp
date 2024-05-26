class Solution {
    int mod=1e9+7;
    int check(int n,int ab,int late,vector<vector<vector<int>>>&dp){
        if(n<=0){
            if(ab>=0&&late<3){
                return 1;
            }
            return 0;
        }
        if(ab<0||late>=3){
            return 0;
        }
        if(dp[n][ab][late]!=-1){
            return dp[n][ab][late];
        }
        int pre=check(n-1,ab,0,dp);
        int abs=check(n-1,ab-1,0,dp);
        int lat=check(n-1,ab,late+1,dp);
        int x=(pre+abs)%mod;
        x=(x+lat)%mod;
        return dp[n][ab][late]=x;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        int late=0;
        return check(n,1,late,dp);
    }
};