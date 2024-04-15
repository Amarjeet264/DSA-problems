class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dis(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0}); // {distance, node}
        dis[0] = 0;
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dis[node]) continue; // Skip if not the shortest path to this node so far
            for(auto it:adj[node]){
                int neighbor = it.first;
                int weight = it.second;
                if(dis[neighbor] > dis[node] + weight && dis[node] + weight < disappear[neighbor]){
                    dis[neighbor] = dis[node] + weight;
                    pq.push({dis[neighbor], neighbor});
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dis[i] == INT_MAX){
                ans.push_back(-1);
            } else {
                ans.push_back(dis[i]);
            }
        }
        return ans;
    }
};
