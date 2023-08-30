#define ppi pair<int, pair<int, int>>
class Solution {
    vector<vector<int>>dis;
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dis=vector<vector<int>>(n,vector<int>(m,INT_MAX));
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        dis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int cost=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m){
                    int newcost=0;
                    if(i==grid[r][c]-1){
                        newcost=cost;
                    }
                    else{
                        newcost=cost+1;
                    }
                    if(dis[nrow][ncol]>newcost){
                        dis[nrow][ncol]=newcost;
                        pq.push({newcost,{nrow,ncol}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};