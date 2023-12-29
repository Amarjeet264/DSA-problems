class Solution {
    bool topo(int node,int target,vector<int>adj[],vector<int>&in){
        in[node]=1;
        for(auto it:adj[node]){
            if(it==target){
                return true;
            }
            else{
                if(!in[it]){
                    if(topo(it,target,adj,in)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& que) {
        vector<int>adj[num];
        vector<int>in(num);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            // cout<<pre[i][1]<<" ";
            in[pre[i][1]]++;
        }
        vector<bool>ans;
        for(int i=0;i<que.size();i++){
            vector<int>vis(num,0);
            if(topo(que[i][0],que[i][1],adj,vis)){
               ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};