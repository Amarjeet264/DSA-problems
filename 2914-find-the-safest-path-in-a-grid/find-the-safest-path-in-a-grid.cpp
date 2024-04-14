class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dis[i][j]=0;
                    pq.push({0,{i,j}});
                }
            }
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                int md=abs(r-nr)+abs(c-nc);
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&dis[nr][nc]>d+md){
                    dis[nr][nc]=d+md;
                    pq.push({dis[nr][nc],{nr,nc}});
                }
            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>>pq1;
        pq1.push({dis[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq1.empty()){
            int d=pq1.top().first;
            int r=pq1.top().second.first;
            int c=pq1.top().second.second;
            pq1.pop();
            if(r==n-1&&c==m-1){
                return d;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    pq1.push({min(dis[nr][nc],d),{nr,nc}});
                }
            }
        }
        return 0;
    }
};