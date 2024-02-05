class Solution {
    unordered_map<int,int>mp;
    int call(int prev,vector<int>&arr,int i,vector<vector<int>>&dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int take=0;
        if(mp.find(arr[i]+arr[prev])!=mp.end()){
            take=1+call(i,arr,mp[arr[i]+arr[prev]],dp);
        }
        else{
            return 0;
        }
        return dp[i][prev]=take;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int maxi=0;
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        for(int i=0;i<arr.size();i++){
           for(int j=i+1;j<arr.size();j++){
                maxi=max(maxi,2+call(i,arr,j,dp));
           }
        }
        return maxi<=2?0:maxi;
    }
};