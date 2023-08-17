class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),INT_MAX));
queue<pair<int,pair<int,int>>>q;
vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[0].size();j++){
        if(mat[i][j]==0){
            q.push({0,{i,j}});
            ans[i][j]=0;
            vis[i][j]=1;
        }
    }
}
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

while(!q.empty()){
    int t=q.front().first;
    int r=q.front().second.first;
    int c=q.front().second.second;
    q.pop();
    for(int i=0;i<4;i++){
        int nrow=r+dr[i];
        int ncol=c+dc[i];
        if(nrow>=0&&ncol>=0&&nrow<mat.size()&&ncol<mat[0].size()&&mat[nrow][ncol]==1&&!vis[nrow][ncol]){
            ans[nrow][ncol]=min(ans[nrow][ncol],t+1);
            q.push({t+1,{nrow,ncol}});
            vis[nrow][ncol]=1;
        }
    }
}
return ans;
    }
};