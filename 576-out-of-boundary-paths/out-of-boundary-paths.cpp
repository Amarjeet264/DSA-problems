class Solution {
    int mod=1e9+7;
    int find(int m,int n,int move,int i,int j,vector<vector<vector<int>>>&dp){
        if(move<0)return 0;
        if(i>=m||i<0||j>=n||j<0){
            return 1;
        }
        if(move==0){
            return 0;
        }
        if(dp[move][i][j]!=-1){
            return dp[move][i][j];
        }
        int up=find(m,n,move-1,i-1,j,dp)%mod;
        int right=find(m,n,move-1,i,j+1,dp)%mod;
        int down=find(m,n,move-1,i+1,j,dp)%mod;
        int left=find(m,n,move-1,i,j-1,dp)%mod;
        return dp[move][i][j]= ((up+right)%mod+(left+down)%mod)%mod;
    }
public:
    int findPaths(int m, int n, int move, int start, int col) {
        vector<vector<vector<int>>>dp(move+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return find(m,n,move,start,col,dp);
    }
};