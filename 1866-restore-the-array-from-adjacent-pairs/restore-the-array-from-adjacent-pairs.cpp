class Solution {
    vector<int>ans;
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>in;
        for(int i=0;i<adj.size();i++){
            mp[adj[i][0]].push_back(adj[i][1]);
            mp[adj[i][1]].push_back(adj[i][0]);
            in[adj[i][1]]++;
            in[adj[i][0]]++;
        }
        int node=-1;
        for(auto it:in){
            if(it.second==1){
                node=it.first;
                break;
            }
        }
        queue<int>q;
        q.push(node);
        unordered_map<int,int>vis;
        while(!q.empty()){
            int fr=q.front();
            vis[fr]=1;
            q.pop();
            ans.push_back(fr);
            for(auto it:mp[fr]){
                if(!vis[it])
                q.push(it);
            }
        }
        return ans;
    }
};