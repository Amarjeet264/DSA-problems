class Solution {
    long long score(int a_idx,vector<vector<long long>>&dp,vector<int>&b,int b_idx,vector<int>&a){
        if(a_idx==4){
            return 0;
        }
        if(b_idx==b.size()){
            return -1e12;
        }
        if(dp[a_idx][b_idx]!=-1){
            return dp[a_idx][b_idx];
        }
        long long nottake = score(a_idx,dp,b,b_idx+1,a);
        long long take = a[a_idx]*(long long)b[b_idx] + score(a_idx+1,dp,b,b_idx+1,a);
        return dp[a_idx][b_idx] = max(take,nottake);
    }
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>>dp(a.size(),vector<long long>(b.size(),-1));
        return score(0,dp,b,0,a);
    }
};