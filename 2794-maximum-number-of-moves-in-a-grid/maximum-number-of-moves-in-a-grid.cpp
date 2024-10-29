class Solution {
    int moves(vector<vector<int>>&grid,int c,int r,vector<vector<int>>&dp,int prev){
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int upar=0;
        int samne=0;
        int niche=0;
        if(r-1>=0&&c+1<grid[0].size()&&grid[r-1][c+1]>prev){
            upar=1+moves(grid,c+1,r-1,dp,grid[r-1][c+1]);
        }
        if(c+1<grid[0].size()&&grid[r][c+1]>prev){
            samne=1+moves(grid,c+1,r,dp,grid[r][c+1]);
        }
        if(r+1<grid.size()&&c+1<grid[0].size()&&grid[r+1][c+1]>prev){
           niche=1+moves(grid,c+1,r+1,dp,grid[r+1][c+1]);
        }
        return dp[r][c]= max(upar,max(samne,niche));
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int maxi=0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            maxi=max(maxi,moves(grid,0,i,dp,grid[i][0]));
        }
        return maxi;
    }
};