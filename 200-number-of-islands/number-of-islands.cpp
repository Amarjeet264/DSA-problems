class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void nums(vector<vector<char>>&grid,int row,int col){
        grid[row][col]='@';
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0&&ncol>=0&&nrow<grid.size()&&ncol<grid[0].size()&&grid[nrow][ncol]=='1'){
                nums(grid,nrow,ncol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    nums(grid,i,j);
                }
            }
        }
        return cnt;
    }
};