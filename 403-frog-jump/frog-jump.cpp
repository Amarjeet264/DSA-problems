class Solution {
    unordered_map<int,int>mp;
    bool canDoit(int pos,int prevJ,int n,vector<vector<int>>&dp){
        if(mp[pos] == n-1){
            return 1;
        }
        if(mp[pos]>=n){
            return 0;
        }
        if(dp[mp[pos]][prevJ]!=-1){
            return dp[mp[pos]][prevJ];
        }
        int res = 0;
        for(int unit = -1;unit<=1;unit++){
            int nextPos = pos + prevJ + unit;
            if(nextPos>pos&&mp.find(nextPos)!=mp.end()){
                res = res | canDoit(nextPos,prevJ+unit,n,dp);
            }
        }
        return dp[mp[pos]][prevJ] = res;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1)return 0;
        for(int i =0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return canDoit(1,1,n,dp);
    }
};