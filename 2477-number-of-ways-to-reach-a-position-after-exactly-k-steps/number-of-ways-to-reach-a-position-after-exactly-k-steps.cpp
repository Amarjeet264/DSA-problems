class Solution {
    int mod=1e9+7;
    int x;
    int number(int end,int k,int curr,vector<vector<int>>&dp){
        if(abs(curr-end)>k){
            return 0;
        }
        if(curr==end){
            if(k==0){
                return 1;
            }
        }
        if(k<0)return 0;
        if(k==0){
            return 0;
        }
        int x=curr;
        if(curr<0)x+=5000;
        if(dp[x][k]!=-1){
            return dp[x][k];
        }
        int ghata=number(end,k-1,curr-1,dp);
        int badha=number(end,k-1,curr+1,dp);
        return dp[x][k]= (badha+ghata)%mod;
    }
public:
    int numberOfWays(int start, int end, int k) {
        // int x=2*(end+k+1);
        vector<vector<int>>dp(6000,vector<int>(k+1,-1));
        return number(end,k,start,dp);
    }
};