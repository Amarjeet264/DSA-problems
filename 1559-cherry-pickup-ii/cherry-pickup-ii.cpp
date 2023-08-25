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
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi=-1e9;
                    for(int k=-1;k<=1;k++){
                        for(int l=-1;l<=1;l++){
                            int value = 0;
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+k<0||j2+l<0||j1+k>=grid[0].size()||j2+l>=grid[0].size()){
                                
                                continue;
                            }
                            value+=dp[i+1][j1+k][j2+l];
                            maxi=max(maxi,value);
                        }
                    }
                    dp[i][j1][j2]= maxi;
                 }
            }
        }
        return dp[0][0][m-1];
    }
};