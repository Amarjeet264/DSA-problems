class Solution {
    unordered_map<int,map<vector<int>,int>>dp;
    int n;
    int shopping(vector<int>&price,vector<vector<int>>&special,vector<int>&needs,int idx,vector<int>ds){
        if(idx>=special.size()){
            int ans=0;
            for(int i=0;i<needs.size();i++){
                ans=ans+(needs[i]-ds[i])*price[i];
            }
            return ans;
        }
        if(dp.find(idx)!=dp.end()&&dp[idx].find(ds)!=dp[idx].end()){
            return dp[idx][ds];
        }
        int nottake=shopping(price,special,needs,idx+1,ds);
        int take=INT_MAX;
        bool can=1;
        vector<int>dup=ds;
        for(int i=0;i<n;i++){
            if(special[idx][i]+dup[i]<=needs[i]){
                dup[i]+=special[idx][i];
            }
            else{
                can=0;
            }
        }
        if(can){
            take=special[idx][n]+shopping(price,special,needs,idx,dup);
        }
        return dp[idx][ds]=min(take,nottake);
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n=needs.size();
        vector<int>ds(n,0);
        return shopping(price,special,needs,0,ds);
    }
};