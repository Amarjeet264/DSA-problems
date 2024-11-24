class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int cntneg=0;
        int mini=INT_MAX;
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    cntneg++;
                }
                mini=min(mini,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if(cntneg%2){
            sum-=2*mini;
        }
        return sum;
    }
};