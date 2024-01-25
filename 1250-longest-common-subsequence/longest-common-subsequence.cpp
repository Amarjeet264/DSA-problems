class Solution {
public:
    int longestCommonSubsequence(string s, string str) {
        // string str=s;
        //  reverse(str.begin(),str.end());
         vector<vector<int>>dp(s.length()+1,vector<int>(str.length()+1,-1));
         for(int i=0;i<=s.length();i++){
             dp[i][0]=0;
         }
         for(int i=0;i<=str.length();i++){
             dp[0][i]=0;
         }
         for(int i=1;i<=s.length();i++){
             for(int j=1;j<=str.length();j++){
                 if(s[i-1]==str[j-1]){
                     dp[i][j]=1+dp[i-1][j-1];
                 }
                 else{
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
             }
         }
         return dp[s.length()][str.length()];
    }
};