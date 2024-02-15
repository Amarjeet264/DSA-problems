class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        bool flag=true;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int row=i;
            int col=0;
            vector<int>x;
            while(row>=0&&col<m){
                x.push_back(mat[row][col]);
                row--;
                col++;
            }
            if(flag==false){
                reverse(x.begin(),x.end());
            }
            for(int k=0;k<x.size();k++){
                ans.push_back(x[k]);
            }
            flag=!flag;
        }
        for(int j=1;j<m;j++){
            int row=n-1;
            int col=j;
            vector<int>x;
            while(row>=0&&col<m){
                x.push_back(mat[row][col]);
                row--;
                col++;
            }
            if(flag==false){
                reverse(x.begin(),x.end());
            }
            for(int k=0;k<x.size();k++){
                ans.push_back(x[k]);
            }
            flag=!flag;
        }
        return ans;
    }
};