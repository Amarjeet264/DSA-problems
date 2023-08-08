class Solution {
    void make(vector<int>&dis,vector<int>&par,int distance,int node,vector<int>adj[],int vis){
        dis[node]=distance;
        par[node]=vis;
        for(auto it:adj[node]){
            if(it!=vis){
                make(dis,par,distance+1,it,adj,node);
            }
        }
    }
    int dfs2(int u,vector<int>&amount,vector<int>adj[],int p=0){
        int ret = amount[u];
        int mxc = -INT_MAX;
        for(int v:adj[u]){
            if(v!=p){
                mxc= max(mxc,dfs2(v,amount,adj,u));
            }
        }
        if(mxc==-INT_MAX)return ret;
        else return ret+mxc;
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
        // int bobdist=0;
        // int bobnode=bob;
        // while(bobnode!=0){
        //     if(dis[bobnode]>bobdist){
        //         amount[bobnode]=0;
        //     }
        //     else if(dis[bobnode]==bobdist){
        //         amount[bobnode]/=2;
        //     }
        //     bobnode=par[bobnode];
        //     bobdist++;
        // }
        return dfs2(0,amount,adj);
    }
};