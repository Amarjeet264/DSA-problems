class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& trains, int source, int destination, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<trains.size();i++){
            adj[trains[i][0]].push_back({trains[i][1],trains[i][2]});
        }
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,source}});
        vector<int>dis(n,INT_MAX);
        dis[source]=0;
        while(!pq.empty()){
            int d=pq.front().first;
            int stops=pq.front().second.first;
            int node=pq.front().second.second;
            // if(node==destination){
            //     pq.pop();
            //     continue;
            // }
            pq.pop();
            if(stops>k)continue;
            for(auto it:adj[node]){
                int w=it.second;
                int adjn=it.first;
                if(dis[adjn]>d+w){
                    dis[adjn]=d+w;
                    pq.push({d+w,{stops+1,adjn}});
                }
            }
        }
        return dis[destination]==INT_MAX?-1:dis[destination];
    }
};