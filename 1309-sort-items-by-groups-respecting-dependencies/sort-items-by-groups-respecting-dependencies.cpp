class Solution {
    void topo(vector<int>adj[],vector<int>&in,vector<int>&a){
        queue<int>q;
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            a.push_back(node);
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before) {
        vector<int>adj[n];
        vector<int>in(n,0);
        for(int i=0;i<before.size();i++){
            for(auto it:before[i]){
                adj[it].push_back(i);
                in[i]++;
            }
        }
        vector<int>a;
        topo(adj,in,a);
        if(a.size()!=n){
            return {};
        }
        unordered_map<int,int>grp;
        for(int i=0;i<group.size();i++){
            if(group[i]==-1){
                grp[i]=m++;
            }
            else{
                grp[i]=group[i];
            }
        }
        vector<int>adj1[m];
        vector<int>in1(m,0);
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                if(grp[i]!=grp[before[i][j]]){
                    adj1[grp[before[i][j]]].push_back(grp[i]);
                    in1[grp[i]]++;
                }
            }
        }
        unordered_map<int,vector<int>>mp1;
        for(int i=0;i<n;i++){
            mp1[grp[a[i]]].push_back(a[i]);
        }
        queue<int>q1;
        for(int i=0;i<m;i++){
            if(in1[i]==0){
                q1.push(i);
            }
        }
        vector<int>ans;
        while(!q1.empty()){
            int gr=q1.front();
            q1.pop();
            for(auto it:mp1[gr]){
                ans.push_back(it);
            }
            for(auto it:adj1[gr]){
                in1[it]--;
                if(in1[it]==0){
                    q1.push(it);
                }
            }
        }
        if(ans.size()!=n)return {};
        return ans;
    }
};