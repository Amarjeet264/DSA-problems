class Solution {
    int rb1(vector<int>&nums,int i,vector<int>&dp1){
        if(i<0){
            return 0;
        }
        if(dp1[i]!=-1){
            return dp1[i];
        }
        if(i==0){
            return nums[0];
        }
        int nottake=rb1(nums,i-1,dp1);
        int take=nums[i]+rb1(nums,i-2,dp1);
        return dp1[i]= max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp1(nums.size(),-1);
        return max(rb1(nums,nums.size()-1,dp1),rb1(nums,nums.size()-2,dp1));
    }
};