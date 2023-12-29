class Disjointset{
    public:
    vector<int>size,parent;
    Disjointset(int n){
        parent.resize(n+1,0);
        size.resize(n+1);
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        Disjointset ds(n);
        for(auto it:edges){
            ds.unionbyr(it[0],it[1]);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int ulp=ds.findulpar(i);
            mp[ulp]++;
        }
        long long ans=0;
        for(auto it:mp){
            int cnt=it.second;
            ans+=(long)(cnt)*(n-cnt);
        }
        return ans/2;
    }
};