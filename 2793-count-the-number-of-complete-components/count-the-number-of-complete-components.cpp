class Solution {
    void dfs(int &cntn,int &cnte,vector<int>adj[],vector<int>&vis,int node){
        vis[node]=1;
        cntn++;
        for(auto it:adj[node]){
                cnte++;
            if(!vis[it]){
                dfs(cntn,cnte,adj,vis,it);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cntn=0;
                int cnte=0;
                dfs(cntn,cnte,adj,vis,i);
                if(cnte==(cntn*(cntn-1))){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};