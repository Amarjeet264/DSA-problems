class Solution {
    int costcalc(vector<int>&houses,vector<vector<int>>&cost,int m,int n,int target,int i,int prev,vector<vector<vector<int>>>&dp){
        if(i>=m){
            if(0==target)return 0;
            return 1e9;
        }
        if(target<0)return 1e9;
        if(dp[i][target][prev]!=-1){
            return dp[i][target][prev];
        }
        int take=0;
        int mini=INT_MAX;
        if(houses[i]==0){
            for(int j=1;j<=n;j++){
                if(j==prev){
                    take=cost[i][j-1]+costcalc(houses,cost,m,n,target,i+1,prev,dp);
                }
                else{
                    take=cost[i][j-1]+costcalc(houses,cost,m,n,target-1,i+1,j,dp);
                }
                mini=min(mini,take);
            }
        }
        else{
            if(houses[i]==prev){
                return dp[i][target][prev]= costcalc(houses,cost,m,n,target,i+1,prev,dp);
            }
            else{
                return dp[i][target][prev]= costcalc(houses,cost,m,n,target-1,i+1,houses[i],dp);
            }
        }
        return dp[i][target][prev]=mini;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>>dp(houses.size(),vector<vector<int>>(target+1,vector<int>(22,-1)));
        int x=costcalc(houses,cost,m,n,target,0,21,dp);
        return x>=1e9?-1:x;
    }
};