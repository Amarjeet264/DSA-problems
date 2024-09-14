class Solution {
    int turbu(vector<int>&arr,int idx ,int flag,vector<vector<int>>&dp){
        if(idx>=arr.size()){
            return 0;
        }
        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        int take = 0;
        if(flag&&arr[idx]>arr[idx-1]){
            take = 1+turbu(arr,idx+1,0,dp);
        }
        else if(!flag&&arr[idx]<arr[idx-1]){
            take = 1+turbu(arr,idx+1,1,dp);
        }
        else{
            take = 0;
        }
        return dp[idx][flag] = take;
    }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxAns = 1;
        if(arr.size()==0){
            return 0;
        }
        vector<vector<int>>dp(arr.size(),vector<int>(2,-1));
        for(int i = 1;i<arr.size();i++){
            int nextSmall = turbu(arr,i,0,dp);
            int nextBig = turbu(arr,i,1,dp);
            maxAns = max(maxAns,1+max(nextSmall,nextBig));
        }
        return maxAns;
    }
};