class Solution {
    int ispalin(string &s,int i,int j){
        int cnt=0;
        while(i<j){
            if(s[i]!=s[j]){
                cnt++;
            }
            i++;
            j--;
        }
        return cnt;
    }
    int palin(string &s,int i,int k,vector<vector<int>>&dp){
        if(i>=s.size()){
            if(k>0)return 1e5;
            return 0;
        }
        if(k==0){
            return 1e5;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int take=1e5;
        for(int j=i;j<s.size();j++){
            int cnt=ispalin(s,i,j);
            if(cnt==0){
                take=min(take,palin(s,j+1,k-1,dp));
            }
            else{
                take=min(take,cnt+palin(s,j+1,k-1,dp));
            }
        }
        return dp[i][k]= take;
    }
public:
    int palindromePartition(string s, int k) {
        vector<vector<int>>dp(s.size(),vector<int>(k+1,-1));
        return palin(s,0,k,dp);
    }
};