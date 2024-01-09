class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        queue<pair<int, int>>q;
        q.push({0,0});
        dis[0][0]=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row==n-1&&col==m-1){
                continue;
            }
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&dis[nrow][ncol]>max(dis[row][col],abs(heights[nrow][ncol]-heights[row][col]))){
                    dis[nrow][ncol]=max(dis[row][col],abs(heights[nrow][ncol]-heights[row][col]));
                    q.push({nrow,ncol});
                }
            }
        }
        return dis[n-1][m-1]==1e9?-1:dis[n-1][m-1];
    }
};