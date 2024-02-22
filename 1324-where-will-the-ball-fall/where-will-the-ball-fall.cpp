class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        for(int j=0;j<grid[0].size();j++){
            int col=j;
            int row=0;
            int x=-1;
            while(row<grid.size()&&col>=0&&col<grid[0].size()){
                if(grid[row][col]==1){
                    if(col+1<grid[0].size()&&grid[row][col+1]!=-1){
                        row++;
                        col++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(col-1>=0&&grid[row][col-1]!=1){
                        row++;
                        col--;
                    }
                    else{
                        break;
                    }
                }
                if(row==grid.size()){
                    x=col;
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;    
    }
};