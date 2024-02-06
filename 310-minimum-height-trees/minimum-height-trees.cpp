class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>in(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            in[edges[i][0]]++;
            in[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int sz=q.size();
            vector<int>dup;
            for(int i=0;i<sz;i++){
                int node=q.front();
                q.pop();
                dup.push_back(node);
                for(auto it:adj[node]){
                    in[it]--;
                    if(in[it]==1){
                        q.push(it);
                    }
                }
            }
            if(q.empty())return dup;
        }
        if(n==1)return {0};
        return {};
    }
};