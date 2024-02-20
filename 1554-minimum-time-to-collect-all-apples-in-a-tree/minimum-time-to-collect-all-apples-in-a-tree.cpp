class Solution {
    vector<bool>has;
    void dfs(int node,vector<int>adj[],int par,vector<bool>&hasApp){
        has[node]=hasApp[node];
        for(auto it:adj[node]){
            if(it!=par){
                dfs(it,adj,node,hasApp);
                has[node]=has[node]|has[it];
            }
        }
    }
    int ans=0;
    void dfs1(int node,vector<int>adj[],int par){
        if(!has[node]){
            return;
        }
        if(node!=0){
            ans+=2;
        }
        for(auto it:adj[node]){
            if(it!=par){
                dfs1(it,adj,node);
            }
        }
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApp) {
        has.resize(n);
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,adj,-1,hasApp);
        for(int i=0;i<n;i++){
            cout<<has[i]<<" ";
        }
        dfs1(0,adj,-1);
        return ans;
    }
};