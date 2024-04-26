class Solution {
    int fall(int i,vector<vector<int>>&grid,int prev,vector<vector<int>>&dp){
        if(i>=grid.size()){
            return 0;
        }
        // if(j>=grid[0].size()||j<0){
        //     return 1e9;
        // }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int take=INT_MAX;
        for(int k=0;k<grid[0].size();k++){
            if(prev!=k)take=min(take,grid[i][k]+fall(i+1,grid,k,dp));
        }
        return dp[i][prev]=take;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini=INT_MAX;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size()+1,-1));
        for(int i=0;i<grid[0].size();i++){
            mini=min(mini,grid[0][i]+fall(1,grid,i,dp));
        }
        return mini;
    }
};