class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void dfs(int &count,int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow<0||nrow>=grid.size()||ncol<0||ncol>=grid[0].size()||grid[nrow][ncol]==0){
                count++;
                // cout<<nrow<<" "<<ncol<<" ";
            }
            else{
                if(!vis[nrow][ncol])
                return dfs(count,nrow,ncol,grid,vis);
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),-1));
        int n=grid.size();
        int count=0;
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(count,i,j,grid,vis);
                }
            }
        }
         return count;
        return 0;
    }
};