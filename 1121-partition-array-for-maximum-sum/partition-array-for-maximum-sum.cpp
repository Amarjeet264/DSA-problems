class Solution {
    int maxsum(vector<int>&arr,int i,int k,vector<int>&dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi=0;
        int sum=0;
        int maxisum=0;
        for(int j=i;j<i+k&&j<arr.size();j++){
            maxi=max(maxi,arr[j]);
            sum=(maxi*(j-i+1))+maxsum(arr,j+1,k,dp);
            maxisum=max(maxisum,sum);
        }
        return dp[i]= maxisum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return maxsum(arr,0,k,dp);
    }
};