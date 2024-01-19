class Solution {
    int find(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        if(i>=n||j>=m||i<0||j<0){
            return 1e9;
        }
        if(i==n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=1e9){
            return dp[i][j];
        }
        int d=find(i+1,j,dp,matrix);
        int ld=find(i+1,j-1,dp,matrix);
        int dia=find(i+1,j+1,dp,matrix);
        return dp[i][j]=matrix[i][j]+min(d,min(ld,dia));
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,find(0,i,dp,matrix));
        }
        return mini;
    }
};