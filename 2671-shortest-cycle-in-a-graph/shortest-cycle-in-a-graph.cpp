class Solution {
    int mini=INT_MAX;
    void bfs(int n,vector<int>adj[],int node){
        vector<int>countnodes(n+1,1e9);
        queue<pair<int,int>>q;
        q.push({node,-1});
        countnodes[node]=0;
        while(!q.empty()){
            int node1=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node1]){
                if(countnodes[it]==1e9){
                    countnodes[it]=countnodes[node1]+1;
                    q.push({it,node1});
                }
                else{
                    if(it!=par){
                        mini=min(mini,countnodes[node1]+1+countnodes[it]);
                    }
                }
            }
        }
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
      vector<int>adj[n];
      for(auto &e:edges){
          adj[e[0]].push_back(e[1]);
          adj[e[1]].push_back(e[0]);
      }
      for(int i=0;i<n;i++){
        bfs(n,adj,i);
      }
      if(mini==INT_MAX)return -1;
      return mini;
    }
};