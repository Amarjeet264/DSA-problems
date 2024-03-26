class Solution {
    long long add(vector<pair<int,int>>adj[],int source,int target,vector<int>&cost,vector<int>&vis){
        // priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        // pq.push({0,s});
        // while(!pq.empty()){
        //     int st=pq.top().second;
        //     long long c=pq.top().first;
        //     pq.pop();
        //     if(st==t){
        //         return c;
        //     }
        //     for(auto it:adj[st]){
        //         pq.push({c+it.second,it.first});
        //     }
        // }
        // return -1;
        vis[source]=0;
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                int naya=it.first;
                int cos=it.second;
                if(vis[naya]>vis[node]+cos){
                    vis[naya]=vis[node]+cos;
                    q.push(naya);
                }
            }
        }
        return vis[target];
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<int,int>>adj[26];
        for(int i=0;i<cost.size();i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        long long ans=0;
        map<pair<int,int>,long long>mp;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]){
                ans+=0;
            }
            else{
                vector<int>vis(26,INT_MAX);
                long long x=-1;
                if(mp.find({source[i]-'a',target[i]-'a'})==mp.end()){
                    x=add(adj,source[i]-'a',target[i]-'a',cost,vis);
                    mp[{source[i]-'a',target[i]-'a'}]=x;
                }
                else{
                    x=mp[{source[i]-'a',target[i]-'a'}];
                }
                if(x==INT_MAX){
                    return -1;
                }
                ans+=x;
            }
        }
        return ans;
    }
};