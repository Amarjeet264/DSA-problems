class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        queue<pair<int,int>>q;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1||i==0||j==0||j==m-1){
                    if(board[i][j]=='O'){
                        q.push({i,j});
                        board[i][j]='@';
                    }
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&board[nrow][ncol]=='O'){
                    board[nrow][ncol]='@';
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='@'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

    }
};