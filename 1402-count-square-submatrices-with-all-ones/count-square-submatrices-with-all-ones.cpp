class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int count=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){

                if(matrix[i][j]==1)
                    matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]))+1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=matrix[i][j];
            }
        }
        return count;
    }
};