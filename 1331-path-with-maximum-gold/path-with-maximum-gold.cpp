class Solution {
    int find(int i,int j,vector<vector<int>>&grid,int n,int m,vector<vector<int>>&vis){
        if(i>=n||i<0||j>=m||j<0||grid[i][j]==0||vis[i][j]==1){
            return 0;
        }
        vis[i][j]=1;
        int left=0;
        int right=0;
        int up=0;
        int down=0;
        left=find(i,j-1,grid,n,m,vis);
        right=find(i,j+1,grid,n,m,vis);
        up=find(i-1,j,grid,n,m,vis);
        down=find(i+1,j,grid,n,m,vis);
        vis[i][j]=0;
        return grid[i][j]+max(max(left,right),max(up,down));
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    maxi=max(maxi,find(i,j,grid,n,m,vis));
                }
            }
        }
        return maxi;
    }
};