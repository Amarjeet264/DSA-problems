class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i = 0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        q.push({0,{0,src}});
        dist[src] = 0;
        int mini = INT_MAX;
        while(!q.empty()){
            auto it = q.front();
            int d = it.first;
            int stops = it.second.first;
            int node = it.second.second;
            q.pop();
            if(stops>k+1){
                continue;
            }
            if(node == dst){
                mini = min(mini,d);
                continue;
            }
            for(auto adjNode:adj[node]){
                if(dist[adjNode.first]>d+adjNode.second){
                    dist[adjNode.first] = d+adjNode.second;
                    q.push({dist[adjNode.first],{stops+1,adjNode.first}});
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};