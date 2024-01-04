class Solution {
    bool dfs(int start,int end,vector<int>adj[],vector<int>&vis,vector<int>&totalvis){
        vis[start]=1;
        if(start==end){
            return true;
        }
        for(auto it:adj[start]){
            if(!vis[it]){
                if(dfs(it,end,adj,vis,totalvis)){
                   totalvis[it]++;
                   return true;
                }
            }
        }
        return false;
    }

    int solve(vector<int>adj[],int curr,int prev,vector<int>&price,vector<int>&dp){
        if(dp[curr]!=-1){
            return dp[curr];
        }
        int nottake=0;
        int take=0;
        for(auto it:adj[curr]){
            if(it!=prev){
                nottake+=solve(adj,it,curr,price,dp);
            }
        }
        take=price[curr];
        for(auto it:adj[curr]){
            if(it!=prev){
                for(auto it1:adj[it]){
                    if(it1!=curr){
                        take+=solve(adj,it1,it,price,dp);
                    }
                }
            }
        }
        return dp[curr]=max(take,nottake);
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>totalvis(n,0);
        for(auto it:trips){
            totalvis[it[0]]++;
            vector<int>vis(n,0);
            dfs(it[0],it[1],adj,vis,totalvis);
        }

        for(int i=0;i<n;i++)
            price[i]=price[i]*totalvis[i]; 
        
        int withouthalf=0;
        for(int i=0;i<n;i++){
            withouthalf+=price[i]; 
        } 
        vector<int>dp;
        dp.resize(n,-1);
        
        int mx=solve(adj,0,-1,price,dp);
     
        return withouthalf-(mx/2);
    }
};