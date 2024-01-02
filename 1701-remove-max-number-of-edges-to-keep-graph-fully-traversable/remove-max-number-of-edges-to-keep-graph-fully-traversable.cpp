#include <bits/stdc++.h>
using namespace std;
class Disjointset{
    public:
    vector<int> parent,sizes;
    Disjointset(int n){
        parent.resize(n);
        sizes.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            sizes[i]=1;
        }
    }
    int findulpar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findulpar(parent[node]);
    }
    void unionbyr(int u,int v){
        int ulpu=findulpar(u);
        int ulpv=findulpar(v);
        if(ulpu==ulpv){
            return;
        }
        if(sizes[ulpu]>sizes[ulpv]) swap(ulpu,ulpv);
            parent[ulpu]=ulpv;
            sizes[ulpv]+=sizes[ulpu];
    }
    int maxSize()
    {
        int cnt=0;
        for(auto i:sizes)
        {
            cnt=max(cnt,i);
        }
        return cnt;
    }
};

class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int cnt=0;
        Disjointset ds1(n+1),ds2(n+1);
        sort(edges.begin(),edges.end(),comp);
        for(auto it:edges){
            int type=it[0];
            int x=it[1];
            int y=it[2];
            if(type==3){
                if(ds1.findulpar(x)==ds1.findulpar(y)){
                    cnt++;
                }
                else{
                    ds1.unionbyr(x,y);
                    ds2.unionbyr(x,y);
                }
            }
            else if(type==2){
                if(ds2.findulpar(x)==ds2.findulpar(y)){
                    cnt++;
                }
                else ds2.unionbyr(x,y);
            }
            else{
                if(ds1.findulpar(x)==ds1.findulpar(y)){
                    cnt++;
                }
                else ds1.unionbyr(x,y);
            }
        }
        if(ds1.maxSize()!=n||ds2.maxSize()!=n)return -1;
        // Disjointset ds(n+1);
        // for(auto it:edges){
        //     if(it[0]==3){
        //         int x=it[1];
        //         int y=it[2];
        //         ds.unionbyr(x,y);
        //     }
        // }

        // Disjointset ds1(n+1);
        // int cnt=0;
        // for(auto it:edges){
        //     if(it[0]==1){
        //         int x=it[1];
        //         int y=it[2];
        //         if(ds.findulpar(x)==ds.findulpar(y)||ds1.findulpar(x)==ds1.findulpar(y)){
        //             cnt++;
        //         }
        //         else ds1.unionbyr(x,y);
        //     }
        // }
        // int x=ds1.findulpar(1);
        // Disjointset ds2(n+1);
        // for(auto it:edges){
        //     if(it[0]==2){
        //         int x=it[1];
        //         int y=it[2];
        //         if(ds.findulpar(x)==ds.findulpar(y)||ds2.findulpar(x)==ds2.findulpar(y)){
        //             cnt++;
        //         }
        //         else ds2.unionbyr(x,y);
        //     }
        // }
        return cnt;
    }
};