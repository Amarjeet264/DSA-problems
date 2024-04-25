class Solution {
    // int longest(string &s,int k,int i,int prev,vector<vector<int>>&dp){
    //     if(i>=s.size()){
    //         return 0;
    //     }
    //     if(dp[i][prev]!=-1){
    //         return dp[i][prev];
    //     }
    //     int take=0;
    //     int nottake=longest(s,k,i+1,prev,dp);
    //     if(abs(s[prev]-s[i])<=k||prev==s.length()){
    //         take=1+longest(s,k,i+1,i,dp);
    //     }
    //     return dp[i][prev]= max(take,nottake);
    // }
public:
    int longestIdealString(string s, int k) {
        // vector<vector<int>>dp(s.size(),vector<int>(s.length()+1,-1));
        // return longest(s,k,0,s.length(),dp);
        vector<int> dp(150,0);
            int ans=0;
            for(auto &i:s){
                for(int j=i-k;j<=i+k;j++){
                    dp[i]=max(dp[i],dp[j]);
                }
                ans=max(ans,++dp[i]);
            }
        return ans;
    }
};