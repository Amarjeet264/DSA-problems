class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>adj[26];
        vector<int>in(26);
        for(int i=0;i<order.size()-1;i++){
            adj[order[i]-'a'].push_back(order[i+1]-'a');
            in[order[i+1]-'a']++;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
        }
        unordered_map<int,int>vis;
        queue<int>q;
        for(int i=0;i<order.size();i++){
            if(mp.find(order[i]-'a')!=mp.end()){
                q.push(order[i]-'a');
                vis[order[i]-'a']++;
                break;
            }
        }
        string ans="";
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            int freq=mp[ele];
            while(freq--){
                ans+=(ele+'a');
            }
            for(auto it:adj[ele]){
                in[it]--;
                if(in[it]==0&&mp.find(it)!=mp.end()){
                    vis[it]++;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<s.size();i++){
            if(!vis[s[i]-'a']){
                ans+=s[i];
            }
        }
        return ans;
    }
};