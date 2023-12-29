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
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        Disjointset ds(26);
        for(auto it:equations){
            if(it[1]=='='){
                ds.unionbyr(it[0]-'a',it[3]-'a');
            }
        }
        for(auto it:equations){
            if(it[1]=='!'){
                if(ds.findulpar(it[0]-'a')==ds.findulpar(it[3]-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};