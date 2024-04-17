class Solution {
    void dfs(vector<int>&vis,int node,vector<int>adj[],vector<int>&x){
        x.push_back(node);
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(vis,it,adj,x);
            }
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int>adj[s.length()];
        for(auto it:pairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(s.length(),0);
        vector<vector<int>>vec;
        for(int i=0;i<s.length();i++){
            vector<int>x;
            if(!vis[i])dfs(vis,i,adj,x);
            vec.push_back(x);
        }
        unordered_map<int,char>mp;
        for(int i=0;i<vec.size();i++){
            sort(vec[i].begin(),vec[i].end());
            string x="";
            for(int j=0;j<vec[i].size();j++){
                x+=s[vec[i][j]];
                // cout<<vec[i][j]<<" ";
            }
            cout<<endl;
            sort(x.begin(),x.end());
            for(int j=0;j<x.size();j++){
                mp[vec[i][j]]=x[j];
            }
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            ans+=mp[i];
        }
        return ans;
    }
};