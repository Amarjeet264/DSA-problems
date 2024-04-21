class Solution {
    int solve(int col,int prev,int n,int m,vector<vector<int>>&cnt,vector<vector<int>>&dp){
        if(col>=m){
            return 0;
        }
        if(dp[col][prev]!=-1){
            return dp[col][prev];
        }
        int ans=INT_MAX;
        for(int j=0;j<=9;j++){
            if(j!=prev){
                ans=min(ans,n-cnt[j][col]+solve(col+1,j,n,m,cnt,dp));
            }
        }
        return dp[col][prev]= ans;
    }
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>cnt(10,vector<int>(m,0));
        for(int c=0;c<m;c++){
            for(int r=0;r<n;r++){
                cnt[grid[r][c]][c]++;
            }
        }
        vector<vector<int>>dp(m,vector<int>(11,-1));
        return solve(0,10,n,m,cnt,dp);
    }
};