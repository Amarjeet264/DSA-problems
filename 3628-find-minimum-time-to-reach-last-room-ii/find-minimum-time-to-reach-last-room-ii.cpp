class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mtime) {
        priority_queue<pair<int,vector<int>>>pq;
        pq.push({0,{0,0,0}});
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        int n = mtime.size();
        int m = mtime[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        while(!pq.empty()){
            int time = -pq.top().first;
            vector<int>x = pq.top().second;
            pq.pop();
            if(x[1]==n-1&&x[2]==m-1){
                return time;
            }
            for(int k =0;k<4;k++){
                int nr = x[1] + dr[k];
                int nc = x[2] + dc[k];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]==0){
                    vis[nr][nc] = 1;
                    if(time<mtime[nr][nc]){
                        pq.push({-(mtime[nr][nc]+x[0]+1),{!x[0],nr,nc}});
                    }
                    else{
                        pq.push({-(time+x[0]+1),{!x[0],nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};