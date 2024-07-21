class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<int>adj[k];
        vector<int>adj1[k];
        vector<int>inr(k);
        vector<int>inc(k);
        for(auto it:row){
            adj[it[0]-1].push_back(it[1]-1);
            inr[it[1]-1]++;
        }
        for(auto it:col){
            adj1[it[0]-1].push_back(it[1]-1);
            inc[it[1]-1]++;
        }
        vector<int>r(k,-1);
        vector<int>c(k,-1);
        queue<int>q;
        for(int i=0;i<k;i++){
            if(inr[i]==0){
                q.push(i);
            }
        }
        int idx=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            r[node]=idx++;
            for(auto it:adj[node]){
                inr[it]--;
                if(inr[it]==0){
                    q.push(it);
                }
            }
        }
        if(idx!=k)return {};
        for(int i=0;i<k;i++){
            if(inc[i]==0){
                q.push(i);
            }
        }
        idx=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            c[node]=idx++;
            for(auto it:adj1[node]){
                inc[it]--;
                if(inc[it]==0){
                    q.push(it);
                }
            }
        }
        if(idx!=k)return {};
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            if(r[i]!=-1&&c[i]!=-1)ans[r[i]][c[i]]=i+1;
        }
        return ans;
    }
};