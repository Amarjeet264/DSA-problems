class Solution {
    vector<int>cosize;
    long long ans=0;
    void dfs(vector<int>adj[],int seats,int node,int par){
        cosize[node]=1;
        for(auto it:adj[node]){
            if(it!=par){
                dfs(adj,seats,it,node);
                cosize[node]+=cosize[it];
            }
        }
        if(node!=0){
            ans=ans+ceil(1.0*cosize[node]/seats);
        }
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int>adj[n+1];
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        cosize.resize(n+1,0);
        dfs(adj,seats,0,-1);
        return ans;
    }
};