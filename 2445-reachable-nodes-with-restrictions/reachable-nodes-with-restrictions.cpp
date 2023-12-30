class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt=0;
        unordered_map<int,int>mp;
        for(auto it:restricted){
            mp[it]++;
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]&&mp.find(it)==mp.end()){
                    cnt++;
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return cnt+1;
    }
};