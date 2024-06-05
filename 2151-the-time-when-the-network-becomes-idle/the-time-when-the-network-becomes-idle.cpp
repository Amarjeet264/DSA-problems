class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
        int n=pat.size();
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        priority_queue<pair<int,int>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dis[it]>dis[node]+1){
                    dis[it]=dis[node]+1;
                    pq.push({-dis[it],it});
                }
            }
        }
        int c=0;
        for(int i=1;i<n;i++){
            dis[i]=2*dis[i];
            if(dis[i]>pat[i]){
                int cap=pat[i]*((dis[i]-1)/pat[i])+dis[i];
                c=max(c,cap);
            }
            c=max(c,dis[i]);
        }
        return c+1;
    }
};