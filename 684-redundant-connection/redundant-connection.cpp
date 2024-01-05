class Solution {
    int parent[1001]={0};
    int findparent(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findparent(parent[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0;i<=edges.size();i++){
            parent[i]=i;
        }
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            int ulpu=findparent(edges[i][0]);
            int ulpv=findparent(edges[i][1]);
            if(ulpu==ulpv){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
            else{
                parent[ulpv]=ulpu;
            }
        }
        return ans;
    }
};