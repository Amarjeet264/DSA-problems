#include <bits/stdc++.h>
using namespace std;
class Disjointset{
    public:
    vector<int>parent,size;
    Disjointset(int n){
        parent.resize(n+1,0);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findulpar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findulpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulpu=findulpar(u);
        int ulpv=findulpar(v);
        if(ulpu==ulpv){
            return;
        }
        if(size[ulpu]<size[ulpv]){
            parent[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
        else{
            parent[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        Disjointset ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    continue;
                }
                for(int k=0;k<4;k++){
                    int nrow=i+dr[k];
                    int ncol=j+dc[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1 )
                    {
                        int u=i*m+j;
                        int v=nrow*m+ncol;
                        // cout<<u<<" "<<v<<"xx  ";
                        ds.unionbysize(u,v);
                    }
                }
            }
        }
        // for(int i=0;i<n*n;i++)
        // cout<<ds.size[i]<<" ";
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    continue;
                }
                set<int>st;
                for(int k=0;k<4;k++){
                    int nrow=i+dr[k];
                    int ncol=j+dc[k];
                    if(nrow<0||nrow>=n||ncol<0||ncol>=m||grid[nrow][ncol]==0){
                        continue;
                    }
                    int v=nrow*n+ncol;
                    st.insert(ds.findulpar(v));
                }
                int cnt=0;
                for(auto it:st){
                    // cout<<it<<" ";
                    cnt+=ds.size[it];
                }
                maxi=max(maxi,cnt+1);
            }
        }
        for(int i=0;i<n*m;i++){
            maxi=max(maxi,ds.size[ds.findulpar(i)]);
        }
        return maxi;
    }
};