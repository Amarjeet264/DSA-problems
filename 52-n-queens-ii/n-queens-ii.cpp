class Solution {
    int count=0;
    bool isposs(int r,int c,vector<string>&board,int n){
        int i=r;
        int j=c;
        while(i>=0&&j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;j--;
        }
        i=r;
        j=c;
        while(i<n&&j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        i=r;
        j=c;
        while(j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            j--;
        }
        return true;
    }
    void find(int c,int n,vector<string>&board){
        if(c==n){
            count+=1;
            return ;
        }
        for(int r=0;r<n;r++){
            if(isposs(r,c,board,n)){
                board[r][c]='Q';
                find(c+1,n,board);
                board[r][c]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string>board(n,"");
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        find(0,n,board);
        return count; 
    }
};