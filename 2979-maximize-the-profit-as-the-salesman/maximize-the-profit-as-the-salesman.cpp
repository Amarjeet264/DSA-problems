class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offer) {
        vector<int>dp(n,0);
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<offer.size();i++){
            mp[offer[i][0]].push_back({offer[i][1],offer[i][2]});
        }

        for(int i=0;i<n;i++){
            for(auto &x:mp[i]){
                if(i==0){
                    dp[x.first]=max(dp[x.first],x.second) ;
                }
                else{
                    dp[x.first]=max(dp[x.first],dp[i-1]+x.second) ;
                }
            }
            if(i>0){
                dp[i]=max(dp[i],dp[i-1]) ;
            }
        }
        
        return dp[n-1];
    }
};