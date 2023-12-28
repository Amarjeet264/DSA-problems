class Solution {
    void dfs(vector<int>&vis,int& cnt,vector<int>adj[],int node){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                cnt++;
                dfs(vis,cnt,adj,it);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            int rad=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i==j)continue;
                long long dis=(long long)(bombs[j][1]-bombs[i][1])*(long long)(bombs[j][1]-bombs[i][1])+
                              (long long)(bombs[j][0]-bombs[i][0])*(long long)(bombs[j][0]-bombs[i][0]);
                if(sqrt(dis)<=rad){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<i<<"->"<<" ";
            for(auto it:adj[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            // if(!vis[i]){
                vector<int>vis(n,0);
                int cnt=1;
                dfs(vis,cnt,adj,i);
                maxi=max(maxi,cnt);
            // }
        }
        return maxi;
    }
};