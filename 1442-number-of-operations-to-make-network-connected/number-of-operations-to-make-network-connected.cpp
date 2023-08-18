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
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset ds(n);
        int extra=0;
        for(int i=0;i<connections.size();i++){
            if(ds.findulpar(connections[i][0])==ds.findulpar(connections[i][1])){
                extra++;
            }
            else{
                ds.unionbysize(connections[i][0],connections[i][1]);
            }
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(ds.findulpar(i)==i){
                comp++;
            }
        }
        if(comp-1<=extra){
            return comp-1;
        }
        return -1;
    }
};