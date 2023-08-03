class Solution {
    bool isposs(int row,int col,char x,vector<vector<char>>&vec){
        int i=row;
        int j=col;
        while(i>=0){
            if(vec[i][j]==x){
                return false;
            }
            i--;
        }
        i=row;
        j=col;
        while(i<9){
            if(vec[i][j]==x){
                return false;
            }
            i++;
        }
        i=row;
        j=col;
        while(j>=0){
            if(vec[i][j]==x){
                return false;
            }
            j--;
        }
        i=row;
        j=col;
        while(j<9){
            if(vec[i][j]==x){
                return false;
            }
            j++;
        }
        for(int i=0;i<9;i++){
            if(vec[3*(row/3)+i/3][3*(col/3)+i%3]==x){
                return false;
            }
        }
        return true;
    }
    bool calls(vector<vector<char>>& board,int c){
        // if(c>=9)return true;
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    for(char i='1';i<='9';i++){
                        if(isposs(r,c,i,board)){
                            board[r][c]=i;
                            bool issol=calls(board,c+1);
                            if(issol){
                                return true;
                            }
                            else{
                                board[r][c]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        calls(board,0);
    }
};