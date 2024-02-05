class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distance) {
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int ans=-1;
        int maxcity=INT_MAX;
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>>pq;
            vector<int>dis(n,1e5);
            pq.push({0,i});
            dis[i]=0;
            while(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                int node=it.second;
                int cost=it.first;
                for(auto x:adj[node]){
                    if(dis[x.first]>cost+x.second){
                        dis[x.first]=cost+x.second;
                        pq.push({dis[x.first],x.first});
                    }
                }
            }
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dis[j]<=distance){
                    cnt++;
                }
            }
            if(cnt<=maxcity){
                maxcity=cnt;
                ans=max(ans,i);
            }
        }
        return ans;
    }
};