class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<walls.size();i++){
            vis[walls[i][0]][walls[i][1]]=INT_MIN;
        }
        for(int i=0;i<guards.size();i++){
            vis[guards[i][0]][guards[i][1]]=INT_MAX;
        }
        for(auto it:guards){
            int row=it[0];
            int col=it[1];
            int x=row;
            int y=col;
            vis[x][y]=1;
            while(x>=0&&(vis[x][y]!=INT_MIN&&vis[x][y]!=INT_MAX)){
                vis[x][y]=1;
                x--;
            }
            x=row;
            y=col;
            vis[x][y]=1;
            while(x<m&&(vis[x][y]!=INT_MIN&&vis[x][y]!=INT_MAX)){
                vis[x][y]=1;
                x++;
            }
            x=row;
            y=col;
            vis[x][y]=1;
            while(y>=0&&(vis[x][y]!=INT_MIN&&vis[x][y]!=INT_MAX)){
                vis[x][y]=1;
                y--;
            }
            x=row;
            y=col;
            vis[x][y]=1;
            while(y<n&&(vis[x][y]!=INT_MIN&&vis[x][y]!=INT_MAX)){
                vis[x][y]=1;
                y++;
            }
            vis[row][col]=INT_MAX;
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};