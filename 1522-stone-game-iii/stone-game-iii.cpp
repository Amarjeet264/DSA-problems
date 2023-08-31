class Solution {
    int stone(int i,vector<int>&piles,vector<vector<int>>&dp,bool can){
        if(i>=piles.size())return 0;
        int res=0;
        if(dp[i][can]!=-1)return dp[i][can];
        if(can){
            res=-1e9;
        }
        else{
            res=INT_MAX;
        }
        int currscore=0;
        for(int k=0;k<=2;k++){
            if(i+k<piles.size())currscore+=piles[i+k];
            if(can){
                res=max(res,currscore+stone(i+k+1,piles,dp,0));
            }
            else{
                res=min(res,stone(i+k+1,piles,dp,1));
            }
        }
        return dp[i][can]= res;
    }
public:
    string stoneGameIII(vector<int>& stoneval) {
        int n=stoneval.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int alice=stone(0,stoneval,dp,1);
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=stoneval[i];
        }
        int bob=tot-alice;
        cout<<tot<<" "<<bob<<" ";
        if(alice>bob){
            return "Alice";
        }
        else if(bob>alice){
            return "Bob";
        }
        return "Tie";
    }
};