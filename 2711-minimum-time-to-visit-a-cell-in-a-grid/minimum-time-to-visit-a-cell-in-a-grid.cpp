class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dis[0][0]=0;
        // if(grid[0][0]>0)return -1;
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        while(!pq.empty()){
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1&&c==m-1)return t;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    int ntime;
                    if(t+1<grid[nr][nc]){
                        ntime=grid[nr][nc];
                        if((ntime-t-1)%2){
                            ntime++;
                        }
                    }
                    else{
                        ntime=t+1;
                    }
                    if(dis[nr][nc]>ntime){
                        dis[nr][nc]=ntime;
                        pq.push({ntime,{nr,nc}});
                    }
                }
            }
        }
        if(dis[n-1][m-1]==INT_MAX)return -1;
        return dis[n-1][m-1];
    }
};