class Solution {
public:
    int solve(int i, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp,int flag) {
        if (i >= nums1.size()) {
            return 0;
        }
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        int take=INT_MAX;
        if(i==0){
            take=min(1+solve(i+1,nums1,nums2,dp,1),solve(i+1,nums1,nums2,dp,0));
        }
        int prev1;
        int prev2;
        if(i!=0){
            if(flag){
                prev1=nums2[i-1];
                prev2=nums1[i-1];
            }
            else{
                prev1=nums1[i-1];
                prev2=nums2[i-1];
            }
        }
        if(i!=0){
            if(prev1<nums1[i]&&prev2<nums2[i]&&nums2[i]>prev1&&nums1[i]>prev2){
                take=min(1+solve(i+1,nums1,nums2,dp,1),solve(i+1,nums1,nums2,dp,0));
            }
            else if(prev1>=nums1[i]||prev2>=nums2[i]){
                take=min(take,1+solve(i+1,nums1,nums2,dp,1));
            }
            else{
                take=min(take,solve(i+1,nums1,nums2,dp,0));
            }
        }
        return dp[i][flag]= take;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        return solve(0, nums1, nums2, dp,0);
    }
};