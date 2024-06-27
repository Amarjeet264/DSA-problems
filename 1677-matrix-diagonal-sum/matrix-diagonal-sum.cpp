class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0;
        int j=0;
        int sum=0;
        while(i<mat.size()&&j<mat[0].size()){
            sum+=mat[i][j];
            i++;
            j++;
        }
        i=0;
        j=mat[0].size()-1;
        if(j==0){
            return sum;
        }
        while(i<mat.size()&&j>=0){
            sum+=mat[i][j];
            i++;
            j--;
        }
        if(mat.size()%2){
            sum-=mat[mat.size()/2][mat.size()/2];
        }
        return sum;
    }
};