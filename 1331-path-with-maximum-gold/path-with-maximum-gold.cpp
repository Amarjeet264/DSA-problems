class Solution {
    int find(int i,int j,vector<vector<int>>&grid,int n,int m){
        if(i>=n||i<0||j>=m||j<0||grid[i][j]==0||grid[i][j]==-1){
            return 0;
        }
        
        int temp=grid[i][j];
        grid[i][j]=-1;
        int left=0;
        int right=0;
        int up=0;
        int down=0;
        left=find(i,j-1,grid,n,m);
        right=find(i,j+1,grid,n,m);
        up=find(i-1,j,grid,n,m);
        down=find(i+1,j,grid,n,m);
        grid[i][j]=temp;
        return temp+max(max(left,right),max(up,down));
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // if(!vis[i][j]){
                    maxi=max(maxi,find(i,j,grid,n,m));
                // }
            }
        }
        return maxi;
    }
};