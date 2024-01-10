class Solution {
    int predict(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int first=nums[i]+min(predict(nums,i+1,j-1,dp),predict(nums,i+2,j,dp));
        int second=nums[j]+min(predict(nums,i+1,j-1,dp),predict(nums,i,j-2,dp));
        return dp[i][j]= max(first,second);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int pehle=predict(nums,0,n-1,dp);
        int dusra=sum-pehle;
        return pehle>=dusra;
    }
};