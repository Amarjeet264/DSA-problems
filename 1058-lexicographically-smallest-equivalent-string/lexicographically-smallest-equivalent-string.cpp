class Solution {
    void dfs(int i,vector<int>&vis,vector<int>adj[],int &mini){
        vis[i]=1;
        // cout<<i<<" ";
        mini=min(mini,i);
        for(auto it:adj[i]){
            if(vis[it]==0){
                dfs(it,vis,adj,mini);
            }
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string base) {
        vector<int>adj[27];
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i])continue;
            adj[s1[i]-'a'].push_back(s2[i]-'a');
            adj[s2[i]-'a'].push_back(s1[i]-'a');
        }
        string ans="";
        for(int i=0;i<base.size();i++){
            // cout<<base[i]<<" ";
            vector<int>vis(27);
            int mini=base[i]-'a';
            dfs(mini,vis,adj,mini);
            ans+=(mini+'a');
        }
        return ans;
    }
};