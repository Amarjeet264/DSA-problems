class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>out(n,0);
        unordered_map<int,vector<int>>parent;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                out[i]++;
                parent[it].push_back(i);
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(out[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            vector<int>dup=parent[node];
            for(int i=0;i<dup.size();i++){
                out[dup[i]]--;
                if(out[dup[i]]==0){
                    q.push(dup[i]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};