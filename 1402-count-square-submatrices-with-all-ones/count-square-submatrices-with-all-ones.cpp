class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0];
        }
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                }
                // else{
                //     dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                // }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt+=dp[i][j];
            }
        }
        return cnt;
    }
};