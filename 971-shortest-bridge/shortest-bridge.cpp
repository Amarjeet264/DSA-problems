class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    queue<vector<int>>q;
    void dfs(int i , int j ,vector<vector<int>>& grid ){
        if(i<0||i>=grid.size() || j<0 || j>= grid[0].size() || grid[i][j] == 2 || grid[i][j] == 0)return;
        grid[i][j] = 2;
        q.push({i,j,0});
        dfs(i , j-1 , grid );
        dfs(i , j+1 , grid );
        dfs(i+1 , j , grid );
        dfs(i-1 , j , grid );
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    f=1;
                    dfs(i,j,grid);
                    break;
                }
            }
            if(f){
                break;
            }
        }
        while(!q.empty()){
            int r=q.front()[0];
            int c=q.front()[1];
            int d=q.front()[2];
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()){
                    if(grid[nr][nc]==1){
                        return d;
                    }
                    if(grid[nr][nc]==2){
                        continue;
                    }
                    grid[nr][nc]=2;
                    q.push({nr,nc,d+1});
                }
            }
        }
        return 0;
    }
};