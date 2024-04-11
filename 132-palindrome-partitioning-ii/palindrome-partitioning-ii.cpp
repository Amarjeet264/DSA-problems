class Solution {
    bool ispalin(string &x,int low,int high){
        int i=low;
        int j=high;
        while(i<j){
            if(x[i]!=x[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    int cut(string &s,int i,vector<int>&dp){
        if(i>=s.length()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=INT_MAX;
        for(int j=i;j<s.length();j++){
            if(ispalin(s,i,j)){
                take=min(take,1+cut(s,j+1,dp));
            }
        }
        return dp[i]= take;
    }
public:
    int minCut(string s) {
        vector<int>dp(s.length(),-1);
        return cut(s,0,dp)-1;
    }
};