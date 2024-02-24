class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<pair<int,int>>adj[],int mini)
    {
        for(auto it:adj[node])
        {
            if(vis[node]<=it.second&&vis[it.first]>it.second)
            {
                vis[it.first]=it.second;
                dfs(it.first,vis,adj,it.second);
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int f) {
        vector<pair<int,int>>adj[n];
        for(auto it:meet)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<int>vis(n,1e9);
        vis[0]=0;
        vis[f]=0;
        dfs(f,vis,adj,0);

        dfs(0,vis,adj,0);

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1e9) ans.push_back(i);
        }
      
        return ans;
    }
};