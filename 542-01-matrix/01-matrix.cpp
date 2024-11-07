class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<mat.size()&&ncol<mat[0].size()&&mat[nrow][ncol]==1&&ans[nrow][ncol]>ans[r][c]+1){
                    ans[nrow][ncol]=ans[r][c]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
};