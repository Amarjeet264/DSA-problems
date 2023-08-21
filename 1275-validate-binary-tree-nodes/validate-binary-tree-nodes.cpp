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
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        vector<int>adj[n];
        vector<int>in(n,0);
        for(int i=0;i<n;i++){
            if(left[i]!=-1){
                adj[i].push_back(left[i]);
                in[left[i]]++;
            }
            if(right[i]!=-1){
                adj[i].push_back(right[i]);
                in[right[i]]++;
            }
        }
        queue<int>q;
        int root=-1;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                if(root==-1)root=i;
                else return false;
            }
        }
        if(root==-1)return false;
        q.push(root);
        vector<int>vis(n,0);
        vis[root]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            int cnt=0;
            for(auto it:adj[node]){
                if(vis[it]){
                    return false;
                }
                vis[it]=1;
                q.push(it);
                cnt++;
            }
            if(cnt>2){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};