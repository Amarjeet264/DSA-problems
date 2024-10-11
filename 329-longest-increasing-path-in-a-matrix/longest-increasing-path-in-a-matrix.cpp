class Solution {
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    int Helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp, int prev)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || prev>=grid[i][j])
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int maxi = 0;
        for(int k = 0;k<4;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            maxi = max(maxi,1+Helper(grid,nr,nc,dp,grid[i][j]));
        }
        dp[i][j] = maxi; 
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0&&m==0){
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        long long int maxi=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maxi<Helper(matrix,i,j,dp,-1)){
                    maxi=Helper(matrix,i,j,dp,-1);
                }
            }
        }
        return maxi;
    }
};