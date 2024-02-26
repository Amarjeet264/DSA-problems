class Solution {
    map<pair<int,int>,int>mp;
    int mct(int left,int right,vector<int>&arr,vector<vector<int>>&dp){
        if(left==right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int mini=INT_MAX;
        for(int i=left;i<right;i++){
            mini=min(mini,mp[{left,i}]*mp[{i+1,right}]+mct(left,i,arr,dp)+mct(i+1,right,arr,dp));
        }
        return dp[left][right]= mini;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            int maxi=arr[i];
            for(int j=i;j<arr.size();j++){
                maxi=max(maxi,arr[j]);
                mp[{i,j}]=max(maxi,mp[{i,j-1}]);
            }
        }
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        return mct(0,arr.size()-1,arr,dp);
    }
};