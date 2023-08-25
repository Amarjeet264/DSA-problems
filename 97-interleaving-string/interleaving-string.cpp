class Solution {
    bool isinter(string s1,string s2,string s3,int i,int j,int k,vector<vector<int>>&dp){
        if(i>=s1.length()&&j>=s2.length()&&k>=s3.length()){
            return true;
        }
        if(k>=s3.length()&&(i<=s1.length()||j<=s2.length())){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool x=0;
        bool y=0;
        if(s1[i]==s3[k]){
            x= isinter(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(s2[j]==s3[k]){
            y= isinter(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j]= x||y;
    }
public:
    bool isInterleave(string A, string B, string C) {
        vector<vector<int>>dp(A.size()+1,vector<int>(B.size()+1,-1));
        return isinter(A,B,C,0,0,0,dp);
    }
};