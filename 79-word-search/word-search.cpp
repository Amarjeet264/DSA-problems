class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int solve(int i,int j,vector<vector<char>>& board,string word,int idx){
        if(idx>=word.size()){
            return true;
        }
        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(nrow>=0&&ncol>=0&&nrow<board.size()&&ncol<board[0].size()&&board[nrow][ncol]==word[idx]){
                int x=board[nrow][ncol];
                board[nrow][ncol]='@';
                if(solve(nrow,ncol,board,word,idx+1)){
                    return true;
                }
                board[nrow][ncol]=x;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    int x=board[i][j];
                    board[i][j]='@';
                    if(solve(i,j,board,word,1)){
                        return true;
                    }
                    board[i][j]=x;
                }
            }
        }
        return false;
    }
};