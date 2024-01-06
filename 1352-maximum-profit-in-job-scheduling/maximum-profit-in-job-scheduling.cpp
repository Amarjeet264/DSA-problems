class Solution {
    int find(int i,vector<vector<int>>&vec,vector<int>&dp,vector<int>&start){
        if(i>=vec.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int nottake=find(i+1,vec,dp,start);
        int take=0;
        int nxtidx=lower_bound(start.begin(),start.end(),vec[i][1])-start.begin();
        take = vec[i][2]+find(nxtidx,vec,dp,start);
        return dp[i] = max(take,nottake);
    }
public:

    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        vector<vector<int>>vec;
        for(int i=0;i<start.size();i++){
            vec.push_back({start[i],end[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        sort(start.begin(),start.end());
        vector<int>dp(start.size()+1,-1);
        return find(0,vec,dp,start); 
    }
};