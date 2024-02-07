#include <bits/stdc++.h>
using namespace std;
class Disjointset{
    public:
    vector<int>size,parent;
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
    void unionbysz(int u,int v){
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
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        Disjointset ds(m*n+1);
        // i*m+j
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int first=i*m+j;
                    for(int k=0;k<4;k++){
                        int row=i+dr[k];
                        int col=j+dc[k];
                        if(row>=0&&row<n&&col>=0&&col<m&&grid[row][col]==1){
                            ds.unionbysz(first,row*m+col);
                        }
                    }
                }
            }
        }
        for(int i=0;i<n*m+1;i++){
            maxi=max(maxi,ds.size[i]);
        }
        if(maxi==1){
            bool pre=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        pre=1;
                    }
                }
            }
            if(!pre){
                return 0;
            }
        }
        return maxi;
    }
};