class Solution {
    int call(vector<int>&nums1,vector<int>&nums2,int i,int can,vector<vector<int>>&dp){
        if(i>=nums1.size()){
            return 0;
        }
        if(dp[i][can]!=-1){
            return dp[i][can];
        }
        int prevele=0;
        if(can){
            prevele=nums1[i-1];
        }
        else{
            prevele=nums2[i-1];
        }
        if(nums1[i]<prevele&&nums2[i]<prevele){
            return 0;
        }
        int first=0;
        int second=0;
        if(nums1[i]==nums2[i]){
            return dp[i][can]= 1+call(nums1,nums2,i+1,1,dp);
        }
        else
            if(nums1[i]>=prevele){
                first=1+call(nums1,nums2,i+1,1,dp);
            }
            if(nums2[i]>=prevele){
                second=1+call(nums1,nums2,i+1,0,dp);
            }
        return dp[i][can]= max(first,second);
    }
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int maxi=0;
        vector<vector<int>>dp(nums1.size(),vector<int>(2,-1));
        for(int i=0;i<nums1.size();i++){
            maxi=max(maxi,1+max(call(nums1,nums2,i+1,0,dp),call(nums1,nums2,i+1,1,dp)));
        }
        return maxi;
    }
};