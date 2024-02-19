class Solution {
    int satish(vector<int>& satis,int i,int fac,vector<vector<int>>&dp){
        if(i>=satis.size()){
            return 0;
        }
        if(dp[i][fac]!=-1){
            return dp[i][fac];
        }
        int nottake=satish(satis,i+1,fac,dp);
        int take=satis[i]*fac+satish(satis,i+1,fac+1,dp);
        return dp[i][fac]= max(take,nottake);
    }
public:
    int maxSatisfaction(vector<int>& satis) {
        sort(satis.begin(),satis.end());
        vector<vector<int>>dp(satis.size(),vector<int>(satis.size()+1,-1));
        int maxi=0;
        for(int i=0;i<satis.size();i++){
            maxi=max(maxi,satish(satis,0,1,dp));
        }
        return maxi;
    }
};