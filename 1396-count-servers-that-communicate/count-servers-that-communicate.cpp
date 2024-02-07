class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    bool is=0;
                    for(int k=0;k<n;k++){
                        if(grid[k][j]==1&&k!=i){

                            is=1;
                        }
                    }
                    for(int k=0;k<m;k++){
                        if(grid[i][k]==1&&k!=j){
                            is=1;
                        }
                    }
                    if(is){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};