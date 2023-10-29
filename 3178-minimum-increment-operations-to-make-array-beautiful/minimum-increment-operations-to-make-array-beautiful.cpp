class Solution {
    long long solve(vector<int>&nums,int k,vector<long long>&dp,int i){
        if(i>nums.size()-3){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long op1=max(0,k-nums[i])+solve(nums,k,dp,i+1);
        long long op2=max(0,k-nums[i+1])+solve(nums,k,dp,i+2);
        long long op3=max(0,k-nums[i+2])+solve(nums,k,dp,i+3);
        return dp[i]=min(op1,min(op2,op3));
    }
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
       vector<long long>dp(nums.size(),-1);
       return solve(nums,k,dp,0);
    }
};