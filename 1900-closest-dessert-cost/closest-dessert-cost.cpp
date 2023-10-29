class Solution {
    int ans=INT_MIN;
    int diff=INT_MAX;
    void solve(vector<int>&top,int target,int sum,int i,vector<vector<int>>&dp){
        if(diff>abs(sum-target)){
            diff=abs(sum-target);
            ans=sum;
        }
        if(diff==abs(sum-target)){
            ans=min(ans,sum);
        }
        if(sum>=target||i>=top.size()){
            return ;
        }
        if(dp[i][sum]!=-1)return ;
        solve(top,target,sum+top[i],i+1,dp);
        solve(top,target,sum+2*top[i],i+1,dp);
        solve(top,target,sum,i+1,dp);
        dp[i][sum]=1;
        
    }
public:
    int closestCost(vector<int>& base, vector<int>& top, int target) {
        for(int i=0;i<base.size();i++){
            vector<vector<int>>dp(top.size(),vector<int>(target+1,-1));
            int sum=base[i];
            solve(top,target,sum,0,dp);
        }
        return ans;
    }
};