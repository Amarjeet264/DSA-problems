class Solution {
    bool rec(unordered_map<int,int>&mp,int idx,int jump,vector<int>&stones,vector<vector<long long>>&dp){
        int pos=stones[idx]+jump;
        if(stones[idx]+jump==stones[stones.size()-1]){
            return true;
        }
        if(stones[idx]+jump>stones[stones.size()-1]){
            return false;
        }
        if(mp.find(pos)==mp.end()){
            return false;
        }
        if(dp[idx][jump]!=-1){
            return dp[idx][jump];
        }
        int naya=mp[pos];
        bool ans=false;
        if(jump>1){
            ans=ans||rec(mp,naya,jump-1,stones,dp);
        }
        ans=ans||rec(mp,naya,jump,stones,dp);
        ans=ans||rec(mp,naya,jump+1,stones,dp);
        return dp[idx][jump]= ans;
    }
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[stones[i]]=i; 
        }
        vector<vector<long long>>dp(n,vector<long long>(n,-1));
        return rec(mp,0,1,stones,dp);
    }
};
