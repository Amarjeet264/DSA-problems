class Solution {
    unordered_map<string,int>mp;
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watched, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<friends[i].size();j++){
                  adj[i].push_back(friends[i][j]);
            }
        }

        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        vis[id]=1;
        q.push({id,0});
        while(!q.empty()){
            int fr=q.front().first;
            int lev=q.front().second;
            q.pop();
            if(lev==level){
                int sz=watched[fr].size();
                for(int i=0;i<sz;i++){
                    mp[watched[fr][i]]++;
                }
                continue;
            }
            for(auto it:adj[fr]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,lev+1});
                }
            }
        }
        vector<pair<int,string>>vec;
        for(auto &it:mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end());
        vector<string>res;
        for(auto &it:vec){
            res.push_back(it.second);
        }
        return res;
    }
};