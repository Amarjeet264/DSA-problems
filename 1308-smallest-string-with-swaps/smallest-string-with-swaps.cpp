class Solution {
    void dfs(vector<int> &dup,int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        dup.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(dup,it,adj,vis);
            }
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int>adj[n];
        for(auto it:pairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n);
        vector<vector<int>>vec;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                vector<int>x;
                dfs(x,i,adj,vis);
                vec.push_back(x);
            }
        }
        unordered_map<int,char>mp;
        for(int i =0;i<vec.size();i++){
            string x = "";
            for(int j =0;j<vec[i].size();j++){
                x+=s[vec[i][j]];
            }
            sort(x.begin(),x.end());
            sort(vec[i].begin(),vec[i].end());
            for(int j=0;j<vec[i].size();j++){
                mp[vec[i][j]] = x[j];
            }
        }
        string ans = "";
        for(int i =0;i<n;i++){
            ans+=mp[i];
        }
        return ans;
    }
};