class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        queue<pair<int, int>>q;
        if(matrix[0][0]==1){
            return -1;
        }
        q.push({0,0});
        dis[0][0]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row==n-1&&col==m-1){
                continue;
            }
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0&&j==0){
                        continue;
                    }
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&dis[nrow][ncol]>dis[row][col]+1&&matrix[nrow][ncol]==0){
                        dis[nrow][ncol]=dis[row][col]+1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return dis[n-1][m-1]==1e9?-1:dis[n-1][m-1];
    }
};