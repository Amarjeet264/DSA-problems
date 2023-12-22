class Solution {
    int maxiwind(int m,int n,vector<int>&ones,vector<int>&zero,int i,vector<vector<vector<int>>>&dp){
        if(i>=ones.size()){
            return 0;
        }
        if(m==0&&n==0){
            return 0;
        }
        if(m<0||n<0){
            return INT_MIN;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int nottake=maxiwind(m,n,ones,zero,i+1,dp);
        int take=0;
        if(m>=zero[i]&&n>=ones[i]){
            take=1+maxiwind(m-zero[i],n-ones[i],ones,zero,i+1,dp);
        }
        return dp[i][m][n]= max(take,nottake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<int>zero(size);
        vector<int>ones(size);
        for(int i=0;i<strs.size();i++){
            int cnt0=0;
            int cnt1=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0'){
                    cnt0++;
                }
                else{
                    cnt1++;
                }
            }
            zero[i]=cnt0;
            ones[i]=cnt1;
        }
        vector<vector<vector<int>>>dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return maxiwind(m,n,ones,zero,0,dp);
    }
};