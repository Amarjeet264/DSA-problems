class Solution {
int find(int i,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i>=grid.size()-1){
            return 0;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int maxi=0;
        for(int k=-1;k<=1;k++){
            for(int l=-1;l<=1;l++){
                if(j1+k<0||j2+l<0||j1+k>=grid[0].size()||j2+l>=grid[0].size()){
                  continue;
                }
                else{
                    if(j1+k==j2+l){
                        maxi=max(maxi,grid[i+1][j1+k]+find(i+1,j1+k,j2+l,grid,dp));
                    }
                    else{
                        maxi=max(maxi,grid[i+1][j1+k]+grid[i+1][j2+l]+find(i+1,j1+k,j2+l,grid,dp));
                    }
                }
            }
        }
        return dp[i][j1][j2]= maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==0)return 0;
        int x=0;
        if(m==1){
            x=grid[0][0];
        }
        else{
            x=grid[0][0]+grid[0][m-1];
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return x+ find(0,0,m-1,grid,dp);
    }
};