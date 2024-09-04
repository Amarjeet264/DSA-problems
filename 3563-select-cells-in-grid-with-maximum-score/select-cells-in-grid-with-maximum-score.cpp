class Solution {
    int dp[101][2001];
    int solve(int val,map<int,vector<int>>&mp,int mask){
        if(val<=0){
            return 0;
        }
        if(dp[val][mask]!=-1){
            return dp[val][mask];
        }
        int nottake = solve(val-1,mp,mask);
        int take = 0;
        for(auto it:mp[val]){
            if((mask&(1<<it))==0){
                take = max(take,val+solve(val-1,mp,mask|(1<<it)));
            }
        }
        return dp[val][mask] =  max(take,nottake);
    }
public:
    int maxScore(vector<vector<int>>& grid) {
        map<int,vector<int>>mp;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                mp[grid[i][j]].push_back(i);
            }
        }
        return solve(100,mp,0);
    }
};