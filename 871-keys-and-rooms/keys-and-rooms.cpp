class Solution {
    void dfs(int node,vector<vector<int>>&rooms,vector<int>&vis){
        vis[node]=1;
        for(auto it:rooms[node]){
            if(!vis[it]){
                dfs(it,rooms,vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),0);
        dfs(0,rooms,vis);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                return 0;
            }
        }
        return 1;
    }
};