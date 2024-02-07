class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>till(n,vector<int>(m,INT_MAX));
        q.push({0,0});
        till[0][0]=grid[0][0];
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow=row+dr[k];
                int ncol=col+dc[k];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&till[nrow][ncol]>till[row][col]){
                    till[nrow][ncol]=max(till[row][col],grid[nrow][ncol]);
                    q.push({nrow,ncol});
                }
            }
        }
        return till[n-1][m-1];
    }
};