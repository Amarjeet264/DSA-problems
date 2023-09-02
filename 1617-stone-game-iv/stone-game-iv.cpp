class Solution {
    bool canwin(int n,vector<int>&dp){
        if(n<=0){
            return false;
        }
        int sc=0;
        long double x= sqrt(n);
        if(dp[n]!=-1)return dp[n];
	    if((int)x * (int)x == n){
		    return true;
	    }
        for(int i=1;i*i<=n;i++){
            sc=i*i;
            if(canwin(n-sc,dp)==0)return dp[n]= true;

        }
        return dp[n]=false;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int>dp(n+n,-1);
        return canwin(n,dp);
    }
};