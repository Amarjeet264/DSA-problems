class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<int>time(n+1,1e9);
        vector<pair<int,int>>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        time[k]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(time[it.first]>time[node]+it.second){
                    time[it.first]=time[node]+it.second;
                    pq.push({time[node]+it.second,it.first});
                }
            }
        }
        int maxi=-1e9;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,time[i]);
        }
        return maxi==1e9?-1:maxi;
    }
};