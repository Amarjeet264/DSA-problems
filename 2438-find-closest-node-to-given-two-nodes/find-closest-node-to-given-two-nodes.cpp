class Solution {
    void bfs(vector<int>&dis,int node,vector<int>adj[],int cnt){
        // vis[node]=1;
        dis[node]=cnt;
        for(auto it:adj[node]){
            if(dis[it]==INT_MIN){
                bfs(dis,it,adj,cnt+1);
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>adj[edges.size()];
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vector<int>dis1(edges.size(),INT_MIN);
        vector<int>dis2(edges.size(),INT_MIN);
        bfs(dis1,node1,adj,0);
        bfs(dis2,node2,adj,0);
        int mini=INT_MAX;
        int idx=-1;
        for(int i=0;i<edges.size();i++){
            if(dis1[i]!=INT_MIN&&dis2[i]!=INT_MIN){
                if(mini>max(dis1[i],dis2[i])){
                    mini=max(dis1[i],dis2[i]);
                    idx=i;
                }
            }
        }
        return idx;
    }
};