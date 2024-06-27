class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minrow=INT_MAX;
        int maxrow=INT_MIN;
        int mincol=INT_MAX;
        int maxcol=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    minrow=min(minrow,i);
                    mincol=min(mincol,j);
                    maxrow=max(maxrow,i);
                    maxcol=max(maxcol,j);
                }
            }
        }
        // cout<<minrow<<" "<<maxrow<<" "<<mincol<<" "<<maxcol<<endl;
        if(minrow==INT_MAX){
            return 0;
        }

        int x=(maxcol-mincol+1)*(maxrow-minrow+1);
        return x;
    }
};