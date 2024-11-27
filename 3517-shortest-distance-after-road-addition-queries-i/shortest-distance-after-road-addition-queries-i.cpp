class Solution {
    int bfs(int src,int dst,vector<int>adj[],int n){
        priority_queue<pair<int,int>>pq;
        pq.push({0,0});
        vector<int>dis(n,INT_MAX);
        dis[0] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int d = -pq.top().first;
            pq.pop();
            if(node==dst){
                return d;
            }
            for(auto it:adj[node]){
                if(dis[node]+1<dis[it]){
                    dis[it] = dis[node] + 1;
                    pq.push({-dis[it],it});
                }
            }
        }
        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        for(int i = 0;i<queries.size();i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            int x = bfs(0,n-1,adj,n);
            ans.push_back(x);
        }
        return ans;
    }
};