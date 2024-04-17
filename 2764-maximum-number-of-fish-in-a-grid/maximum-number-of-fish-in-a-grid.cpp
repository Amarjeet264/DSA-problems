class Solution {
    int n=0;
    int m=0;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void dfs(int &cnt,vector<vector<int>>&grid,int r,int c){
        cnt+=grid[r][c];
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m&&grid[nr][nc]>0){
                dfs(cnt,grid,nr,nc);
            }
        }
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    int cnt=0;
                    dfs(cnt,grid,i,j);
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};