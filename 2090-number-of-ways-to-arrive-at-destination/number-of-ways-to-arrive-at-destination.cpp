class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        int mod=1e9+7;
        vector<long long >ways(n,0);
        vector<long long>dis(n,LONG_MAX);
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>q;
        q.push({0,0});
        dis[0]=0;
        ways[0]=1;
        while(!q.empty()){
            long long d=q.top().first;
            int node=q.top().second;
            q.pop();
            for(auto it:adj[node]){
                int w=it.second;
                int adjn=it.first;
                if(dis[adjn]==d+w){
                    ways[adjn]=(ways[adjn]+ways[node])%mod;
                }
                else if(dis[adjn]>d+w){
                    ways[adjn]=0;
                    dis[adjn]=d+w;
                    ways[adjn]=(ways[node])%mod;
                    q.push({d+w,adjn});
                }
            }
        }
        return ways[n-1]%mod;
    }
};