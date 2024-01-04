class Solution {
    void dfs(int node,vector<pair<int,bool>>adj[],vector<int>&vis,int &cnt){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                if(!it.second){
                    cnt++;
                }
                dfs(it.first,adj,vis,cnt);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,bool>>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back({it[1],false});
            adj[it[1]].push_back({it[0],true});
        }
        int cnt=0;
        vector<int>vis(n,0);
        dfs(0,adj,vis,cnt);
        return cnt;
    }
};