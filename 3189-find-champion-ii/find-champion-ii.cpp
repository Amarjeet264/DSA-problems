class Solution {
    void dfs(vector<int>&vis,int node,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(vis,it,adj);
            }
        }
    }
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(vis,i,adj);
            bool saare=true;
            for(int k=0;k<n;k++){
                if(!vis[k]){
                    saare=false;
                }
            }
            if(saare==true){
                return i;
            }
        }
        return -1;
    }
};