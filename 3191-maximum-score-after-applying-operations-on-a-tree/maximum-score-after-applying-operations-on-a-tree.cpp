class Solution {
    typedef long long ll;
    pair<ll,ll>dfs(vector<int>adj[],vector<int>&values,int node,int parent){
        ll left=0;
        ll taken=0;
        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            pair<ll,ll>x=dfs(adj,values,it,node);
            taken+=x.first;
            left+=x.second;
        }
        if(left!=0){
            taken+=max(left,(ll)values[node]);
            left=min(left,(ll)values[node]);
        }
        else{
            left=values[node];
        }
        return {taken,left};
    }
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        vector<int>adj[values.size()];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(adj,values,0,-1).first;
    }
};