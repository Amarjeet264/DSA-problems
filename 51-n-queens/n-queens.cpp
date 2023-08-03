class Solution {
    bool isposs(int r,int c,vector<string>&board,int n){
        int row=r;
        int col=c;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row=r;
         col=c;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=r;
        col=c;
        while(row<n&&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void calls(vector<vector<string>>&ans,int n,vector<string>&board,int c){
        if(c==n){
            ans.push_back(board);
            return;
        }
        for(int r=0;r<n;r++){
            if(isposs(r,c,board,n)){
                board[r][c]='Q';
                calls(ans,n,board,c+1);
                board[r][c]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        calls(ans,n,board,0);
        return ans;
    }
};