class Solution {
    vector<int>v;
    int cycle(vector<int>&vis,int node,vector<int>adj[],int &cnt){
        vis[node]=1;
        cnt+=1;
        v.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                cycle(vis,it,adj,cnt);
            }
        }
        return 0;
    }
    int calc(int node,vector<int>&ans,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        int x=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                x=1+calc(it,ans,adj,vis);
            }
            else if(vis[it]&&ans[it]!=0){
                x=1+ans[it];
            }
        }
        return ans[node]=x;
    }
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        vector<int>adj[edges.size()];
        int n=edges.size();
        vector<int>in(n,0);
        for(int i=0;i<edges.size();i++){
            adj[i].push_back(edges[i]);
            in[edges[i]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        vector<int>vis(n,0);
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0&&in[i]!=0){
                v.clear();
                int cnt=0;
                cycle(vis,i,adj,cnt);
                for(auto it:v){
                    ans[it]=cnt;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                calc(i,ans,adj,vis);
            }
        }
        return ans;
    }
};