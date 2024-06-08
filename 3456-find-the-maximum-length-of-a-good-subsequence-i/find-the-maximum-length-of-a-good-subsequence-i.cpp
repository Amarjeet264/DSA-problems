class Solution {
    int length(vector<int>&nums,int k,int prev,int i,vector<vector<vector<int>>>&dp){
        if(i>=nums.size()){
            if(k>=0){
                return 0;
            }
            return -1e8;
        }
        if(k<0){
            return -1e8;
        }
        if(dp[i][k][prev+1]!=-1){
            return dp[i][k][prev+1];
        }
        int nottake=length(nums,k,prev,i+1,dp);
        int take=0;
        if(prev==-1||nums[prev]==nums[i]){
            take=1+length(nums,k,i,i+1,dp);
        }
        else{
            take=1+length(nums,k-1,i,i+1,dp);
        }
        return dp[i][k][prev+1]= max(take,nottake);
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(n+1,-1)));
        return length(nums,k,-1,0,dp);
    }
};