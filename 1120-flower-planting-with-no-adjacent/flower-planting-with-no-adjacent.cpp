class Solution {
    bool isposs(int col,int node,vector<int>adj[],vector<int>&vis){
        for(auto it:adj[node]){
            if(vis[it]==col){
                return false;
            }
        }
        return true;
    }
    void dfs(int node,int n,vector<int>adj[],vector<int>&vis){
        for(auto it:adj[node]){
            if(vis[it]==-1){
                for(int col=1;col<=4;col++){
                    if(isposs(col,it,adj,vis)){
                        vis[it]=col;
                        dfs(it,n,adj,vis);
                    }
                }
            }
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>adj[n];
        for(auto it:paths){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vis[i]=1;
                dfs(i,n,adj,vis);
            }
        }
        return vis;
    }
};