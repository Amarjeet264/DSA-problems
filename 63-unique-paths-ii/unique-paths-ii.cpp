class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1){
            return 0;
        }
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    dp[i][j]=1;
                    continue;
                }
                if(grid[i][j]==0){
                    int left=0;
                    int up=0;
                    if(j>0)left=dp[i][j-1];
                    if(i>0)up=dp[i-1][j];
                    dp[i][j]=(left+up);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[n-1][m-1];
    }
};