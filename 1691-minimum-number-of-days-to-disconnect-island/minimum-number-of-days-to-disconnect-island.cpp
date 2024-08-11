class Solution {
    int  dr[4] = {-1,0,1,0};
    int  dc[4] = {0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int &tot){
        vis[i][j] = 1;
        tot+=1;
        for(int k = 0;k<4; k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&grid[nr][nc]&&vis[nr][nc]==0){
                dfs(nr,nc,grid,vis,tot);
            }
        }
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        int  cnt = 0;
        int tot = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]){
                    dfs(i,j,grid,vis,tot);
                    cnt++;
                }
            }
        }
        if(cnt!=1){
            return 0;
        }
        if(tot<=2){
            return tot;
        }
        bool yes = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    vector<vector<int>>vis(n,vector<int>(m));
                    int  cnt = 0;
                    grid[i][j] = 0;
                    for(int k = 0;k<n;k++){
                        for(int l = 0;l<m;l++){
                            if(vis[k][l]==0&&grid[k][l]){
                                dfs(k,l,grid,vis,tot);
                                cnt++;
                            }
                        }
                    }
                    grid[i][j]=1;
                    if(cnt>1){
                        return 1;
                    }
                }
            }
        }
        return 2;
    }
};