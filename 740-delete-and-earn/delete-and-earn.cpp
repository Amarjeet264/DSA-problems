class Solution {
    int find(int i,vector<int>&arr,unordered_map<int,int>&mp,int prev,vector<vector<int>>&dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int nottake=find(i+1,arr,mp,prev,dp);
        int take=0;
        if(prev==arr.size()||abs(arr[i]-arr[prev])!=1)take=arr[i]*mp[arr[i]]+find(i+1,arr,mp,i,dp);
        return dp[i][prev]= max(take,nottake);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int>arr;
        for(auto it:mp){
            arr.push_back(it.first);
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size()+1,-1));
        return find(0,arr,mp,arr.size(),dp);
    }
};