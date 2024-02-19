class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }
    int calc(vector<vector<int>>&vec,int i,int prev,vector<vector<int>>&dp){
        if(i>=vec.size()){
            return 0;
        }
        if(dp[i][prev]!=-1)return dp[i][prev];
        int nottake=calc(vec,i+1,prev,dp);
        int take=0;
        if(prev==vec.size()||vec[i][1]>=vec[prev][1]){
            take=vec[i][0]+calc(vec,i+1,i,dp);
        }
        return dp[i][prev]= max(take,nottake);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>>vec;
        for(int i=0;i<scores.size();i++){
            vec.push_back({scores[i],ages[i]});
        }
        vector<vector<int>>dp(vec.size(),vector<int>(vec.size()+1,-1));
        sort(vec.begin(),vec.end());
        return calc(vec,0,ages.size(),dp); 
    }
};