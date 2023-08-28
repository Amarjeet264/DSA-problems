class NumMatrix {
    vector<vector<long>>dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp=vector<vector<long>>(n+1,vector<long>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]+=dp[i][j-1];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                dp[i][j]+=dp[i-1][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        long x= dp[row2][col2]-(row1!=0?dp[row1-1][col2]:0)-(col1!=0?dp[row2][col1-1]:0)+((row1!=0&&col1!=0)?dp[row1-1][col1-1]:0);
        return (int)x;
    }
};
                  
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */