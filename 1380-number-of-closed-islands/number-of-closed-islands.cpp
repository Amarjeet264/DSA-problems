class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>&grid,int n,int m,bool &can,vector<vector<int>>&vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int row=i+dr[k];
            int col=j+dc[k];
            if(row<0||col<0||row>=n||col>=m){
                // return false;
                can=0;
                continue;
            }
            if(vis[row][col]==0&&grid[row][col]==0){
                dfs(row,col,grid,n,m,can,vis);
            }
        }
        // return 1;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0&&vis[i][j]==0){
                    bool can=1;
                    dfs(i,j,grid,n,m,can,vis);
                    if(can){
                        // cout<<i<<" "<<j<<" "<<endl;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};