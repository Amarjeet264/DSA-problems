class Solution {
    int wiggle(int prev,int pos,vector<int>&nums,int i,vector<vector<vector<int>>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev][pos]!=-1){
            return dp[i][prev][pos];
        }
        int nottake=wiggle(prev,pos,nums,i+1,dp);
        int take=0;
        if(prev==nums.size()){
            take=1+wiggle(i,pos,nums,i+1,dp);
        }
        else{
            if(pos==2){
                if(nums[i]-nums[prev]<0){
                    take=1+wiggle(i,0,nums,i+1,dp);
                }
                else if(nums[i]-nums[prev]>0){
                    take=1+wiggle(i,1,nums,i+1,dp);
                }
            }
            else if(pos==0&&nums[i]-nums[prev]>0){
                take=1+wiggle(i,1,nums,i+1,dp);
            }
            else if(pos==1&&nums[i]-nums[prev]<0){
                take=1+wiggle(i,0,nums,i+1,dp);
            }
        }
        return dp[i][prev][pos]= max(take,nottake);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(3,-1)));
        return wiggle(nums.size(),2,nums,0,dp);
    }
};