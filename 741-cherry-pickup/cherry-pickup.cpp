class Solution {
    int dp[51][51][51][51];
    int find(int i1,int j1,int i2,int j2,vector<vector<int>>&grid){
        if(j1>=grid[0].size()||j2>=grid[0].size()||i1>=grid.size()||i2>=grid.size()){
            return -1e8;
        }
        if(grid[i1][j1]==-1||grid[i2][j2]==-1){
            return -1e8;
        }
        if(i1==grid.size()-1&&j1==grid[0].size()-1){
            return grid[i1][j1];
        }
        if(i2==grid.size()-1&&j2==grid[0].size()-1){
            return grid[i2][j2];
        }
        if(dp[i1][j1][i2][j2]!=0){
            return dp[i1][j1][i2][j2];
        }
        int val=0;
        int maxi=0;
        if(i1==i2&&j1==j2){
            val=grid[i1][j1];
        }
        else{
            int x=grid[i1][j1];
            int y=grid[i2][j2];
            // grid[i1][j1]=0;
            // grid[i2][j2]=0;
            val=x+y;
            // grid[i1][j1]=x;
            // grid[i2][j2]=y;
            // maxi=max(maxi,val);
        }
        val+=max(
        max(find( i1 + 1, j1, i2 + 1, j2,grid), find( i1 + 1, j1, i2 , j2+1,grid)),
        max(find( i1, j1+1, i2 + 1, j2,grid), find( i1, j1+1, i2, j2+1,grid)));
        return dp[i1][j1][i2][j2]= val;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        return max(0,find(0,0,0,0,grid));
    }
};