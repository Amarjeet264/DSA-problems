class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if(i-k<0||i+k>=n||j-k>0||j+k>=m)continue;
                int sum=0;
                for(int x=i-k;x<=i+k;x++){
                    for(int l=j-k;l<=j+k;l++){
                        if(x>=0&&x<n&&l>=0&&l<m)sum+=mat[x][l];
                    }
                }
                ans[i][j]=sum;
            }
        }
        return ans;
    }
};