class DSU{
    vector<int>par;
    vector<int>size;
    public:
    DSU(int n){
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            size[i]=1;
        }
    }
    int findpar(int u){
        if(par[u]==u){
            return u;
        }
        return par[u]=findpar(par[u]);
    }
    void unionbysz(int u,int v){
        int ulpu=findpar(u);
        int ulpv=findpar(v);
        if(ulpu==ulpv){
            return;
        }
        if(size[ulpu]>size[ulpv]){
            par[ulpv]=ulpu;
            size[ulpu]+=size[ulpv];
        }
        else{
            par[ulpu]=ulpv;
            size[ulpv]+=size[ulpu];
        }
    }
    int getsize(int u){
        return size[findpar(u)];
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        for(auto &it:hits){
            if(grid[it[0]][it[1]]==0){
                it[0]=-1;
            }
            else grid[it[0]][it[1]]=0;
        }
        int n=grid.size();
        int m=grid[0].size();
        DSU dsu(m*n+1);
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    if(i==0){
                        dsu.unionbysz(m*n,i*m+j);
                    }
                    for(int k=0;k<4;k++){
                        int nrow=i+dr[k];
                        int ncol=j+dc[k];
                        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]){
                                dsu.unionbysz(i*m+j,nrow*m+ncol);
                        }
                    }
                }
            }
        }
        reverse(hits.begin(),hits.end());
        vector<int>ans;
        for(int x=0;x<hits.size();x++){
            int i=hits[x][0];
            if(i==-1){
                ans.push_back(0);
                continue;
            }
            int j=hits[x][1];
            grid[i][j]=1;
            int curr=dsu.getsize(m*n);
            if(i==0){
                dsu.unionbysz(m*n,i*m+j);
            }
            for(int k=0;k<4;k++){
                int nrow=i+dr[k];
                int ncol=j+dc[k];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]){
                    dsu.unionbysz(i*m+j,nrow*m+ncol);
                }
            }
            int newcurr=dsu.getsize(m*n);
            ans.push_back(max(0,newcurr-curr-1));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};