class Solution {
    void bfs(vector<int>&ans,vector<pair<int,char>>adj[],int n){
         map<pair<int,char>,int>mp;
         priority_queue<pair<int,pair<int,char>>,vector<pair<int,pair<int,char>>>,greater<pair<int,pair<int,char>>>>pq;
        pq.push({0,{0,'R'}});
        pq.push({0,{0,'B'}});
        ans[0]=0;
        mp[{0,'R'}]=1;
        mp[{0,'B'}]=1;
        while(!pq.empty()){
            int dis=pq.top().first;
            char col=pq.top().second.second;
            int node=pq.top().second.first;
            pq.pop();
            for(auto it:adj[node]){
                pair<int,char>p=it;
                if(col!=p.second){
                    if(mp.find({p.first,p.second})==mp.end()){
                        pq.push({dis+1,{p.first,p.second}});
                        mp[{p.first,p.second}]=1;
                    }
                    if(ans[p.first]>dis+1)ans[p.first]=dis+1;
                }
            }
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<pair<int,char>>adj[n];
        for(auto it:red){
            adj[it[0]].push_back({it[1],'R'});
        }
        for(auto it:blue){
            adj[it[0]].push_back({it[1],'B'});
        }
        vector<int>ans(n,INT_MAX);
        ans[0]=0;
        bfs(ans,adj,n);
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
    }
};