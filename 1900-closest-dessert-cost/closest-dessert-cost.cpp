class Solution {
    int ans=INT_MIN;
    int diff=INT_MAX;
    unordered_map<int,int>mp;
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
        if(dp[i][sum]!=-1)return;
        for(int j=i;j<top.size();j++){
            if(mp[j]<2){
                mp[j]++;
                solve(top,target,sum+top[j],j,dp);
                solve(top,target,sum+top[j],j+1,dp);
                mp[j]--;
                if(mp[j]==0)mp.erase(j);
            }
            solve(top,target,sum,j+1,dp);
        }
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