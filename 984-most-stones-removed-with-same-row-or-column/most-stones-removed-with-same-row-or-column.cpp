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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        Disjointset ds(maxrow+maxcol+1);
        unordered_map<int,int>mp;
        for(auto it:stones){
            int row=it[0];
            int col=it[1]+maxrow+1;
            ds.unionbysize(row,col);
            mp[it[0]]=1;
            mp[col]=1;
        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findulpar(it.first)==it.first){
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};