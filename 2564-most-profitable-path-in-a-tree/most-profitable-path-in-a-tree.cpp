class Solution {
    void make(vector<int>&dis,vector<int>&par,int distance,int node,vector<int>adj[],int parent){
        dis[node]=distance;
        par[node]=parent;
        for(auto it:adj[node]){
            if(it!=parent){
                make(dis,par,distance+1,it,adj,node);
            }
        }
    }
    int dfs(int node,vector<int>&amount,vector<int>adj[],int p){
        int am = amount[node];
        int maxi = -INT_MAX;
        for(auto v:adj[node]){
            if(v!=p){
                maxi= max(maxi,dfs(v,amount,adj,node));
            }
        }
        if(maxi==-INT_MAX)return am;
        return am+maxi;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dis(n,0);
        vector<int>par(n,0);
        make(dis,par,0,0,adj,0);
        int len=dis[bob]-dis[0]+1;
        bool odd=false;
        if(len%2!=0)odd=true;
        len/=2;
        while(len){
            amount[bob]=0;
            bob=par[bob];
            len--;
        }
        if(odd){
            amount[bob]/=2;
        }
        return dfs(0,amount,adj,0);
    }
};