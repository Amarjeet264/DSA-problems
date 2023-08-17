#include <bits/stdc++.h>
using namespace std;
class Disjointset{
    vector<int>rank,parent;
    public:
    Disjointset(int n){
        parent.resize(n+1,0);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
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
        if(rank[ulpu]<rank[ulpv]){
            parent[ulpu]=ulpv;
        }
        else if(rank[ulpu]>rank[ulpv]){
            parent[ulpv]=ulpu;
        }
        else{
            parent[ulpv]=ulpu;
            rank[ulpu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>>ans;
        unordered_map<string,int>mp;

        Disjointset ds(accounts.size());

        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                  mp[mail]=i;
                }
                else{
                    ds.unionbyr(i,mp[mail]);
                }
            }
        }
        vector<string>dup[accounts.size()];
        for(auto it:mp){
            string mail=it.first;
            int ulp=ds.findulpar(it.second);
            dup[ulp].push_back(mail);
        }
        for(int i=0;i<accounts.size();i++){
            if(dup[i].size()!=0){
                sort(dup[i].begin(),dup[i].end());
                vector<string>temp;
                temp.push_back(accounts[i][0]);
                for(auto it:dup[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};