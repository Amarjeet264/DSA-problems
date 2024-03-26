class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        unordered_map<int,int>y;
        unordered_map<int,int>noty;
        int n=grid.size();
        int m=grid[0].size();
        int i=0;
        int j=0;
        while(i<=n/2&&j<=m/2){
            y[grid[i][j]]++;
            grid[i][j]=-1;
            i++;
            j++;
        }
        i=0;
        j=m-1;
        while(i<=n/2&&j>=m/2){
            y[grid[i][j]]++;
            grid[i][j]=-1;
            i++;
            j--;
        }
        i=n/2;
        j=m/2;
        while(i<n){
            y[grid[i][j]]++;
            grid[i][j]=-1;
            i++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=-1){
                    noty[grid[i][j]]++;
                }
            }
        }
        int ans=y[1]+y[2]+min(noty[0]+noty[2],noty[0]+noty[1]);
        ans=min(ans,y[0]+y[2]+min(noty[1]+noty[2],noty[0]+noty[1]));
        ans=min(ans,y[0]+y[1]+min(noty[1]+noty[2],noty[0]+noty[2]));
        return ans;
    }
};