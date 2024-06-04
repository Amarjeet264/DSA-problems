class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dis(n+1,INT_MAX);
        vector<int>dis1(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        dis[1]=0;
        int cnt=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if ((d/change)%2 == 1){
                d+=(change-d%change);
            }
            if(node==n){
                cnt++;
            }
            if(cnt==2){
                break;
            }
            for(auto it:adj[node]){
                if(dis[it]>d+time){
                    dis1[it]=dis[it];
                    dis[it]=d+time;
                    pq.push({dis[it],it});
                }
                else if(dis1[it]>d+time&&dis[it]!=d+time){
                    dis1[it]=d+time;
                    pq.push({dis1[it],it});
                }
            }
        }
        return dis1[n];
    }
};