class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(n,0);
        int ans=1e9;
        vis[0]=0;
        while(!q.empty()){
            int node=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(node==n-1){
                ans=min(ans,steps);
                continue;
            }
            if(node-1>=0&&!vis[node-1]){
                vis[node-1]=1;
                q.push({node-1,steps+1});
            }
            if(node+1>=0&&!vis[node+1]){
                vis[node+1]=1;
                q.push({node+1,steps+1});
            }
            for(auto it:mp[arr[node]]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,steps+1});
                }
            }
            mp[arr[node]].clear();
        }
        return ans;
    }
};