class Solution {
    int stone(int i,int j,vector<int>&st,vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=0;
        for(int k=i;k<j;k++){
            int left=0;
            left=st[k];
            if(i!=0)left-=st[i-1];
            int right=0;
            right=st[j]-st[k];
            if(left>=right){
                maxi=max(maxi,right+stone(k+1,j,st,dp));
            }
            if(left<=right){
                maxi=max(maxi,left+stone(i,k,st,dp));
            }
        }
        return dp[i][j]= maxi;
    }
public:
    int stoneGameV(vector<int>& st) {
        for(int i=1;i<st.size();i++){
            st[i]+=st[i-1];
        }
        vector<vector<int>>dp(st.size(),vector<int>(st.size(),-1));
        return stone(0,st.size()-1,st,dp);
    }
};