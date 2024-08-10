class dsu{
    public:
    vector<int>parent,rank;
    dsu(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i = 0;i<n;i++){
            parent[i]=i;
        }
    }
    int findulpar(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findulpar(parent[u]);
    }
    void unionbyr(int u,int v){
        int ulpu = findulpar(u);
        int ulpv = findulpar(v);
        if(ulpv==ulpu){
            return ;
        }
        if(rank[ulpv]>rank[ulpu]){
            parent[ulpu] = ulpv;
            rank[ulpv]+=rank[ulpu];
        }
        else{
            parent[ulpv] = ulpu;
            rank[ulpu] += rank[ulpv];
        }
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int size = (n+1)*(n+1);
        dsu ds(size*size);
        for(int i=1;i<=n;i++){
            int ele = 0 * (n+1) + i;
            ds.unionbyr(0,ele);
            ele = n * (n+1) + i;
            ds.unionbyr(0,ele);
            ele = i * (n+1) + n;
            ds.unionbyr(0,ele);
            ele = i * (n+1);
            ds.unionbyr(0,ele);
        }
        int cnt = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='/'){
                    int u = (i+1) * (n+1) + j;
                    int v = i*(n+1) + (j+1);
                    if(ds.findulpar(u)==ds.findulpar(v)){
                        cnt++;
                    }
                    else{
                        ds.unionbyr(u,v);
                    }
                }
                else if(grid[i][j] == '\\'){
                    int u = (i+1) * (n+1) + (j+1);
                    int v = i*(n+1) + (j);
                    if(ds.findulpar(u)==ds.findulpar(v)){
                        cnt++;
                    }
                    else{
                        ds.unionbyr(u,v);
                    }
                }
            }
        }
        return cnt;
    }
};