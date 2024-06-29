class Solution {
    void kiskiskeme(vector<vector<int>>&ans,int node,vector<int>adj[],int &ye,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                ans[it].push_back(ye);
                kiskiskeme(ans,it,adj,ye,vis);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(n,vector<int>());
        int m=edges.size();
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            kiskiskeme(ans,i,adj,i,vis);
        }
        return ans;
    }
};