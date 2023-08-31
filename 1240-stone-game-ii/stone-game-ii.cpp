class Solution {
    vector<vector<int>>dp;
    int stone(vector<int>&piles,int i,int currtakemax){
        if(i>=piles.size()){
            return 0;
        }
        int maxi=-1e9;
        int tot=0;
        if(dp[i][currtakemax]!=-1)return dp[i][currtakemax];
        for(int k=0;k<2*currtakemax;k++){
            if(i+k<piles.size())tot+=piles[i+k];
            maxi=max(maxi,tot-stone(piles,i+k+1,max(currtakemax,1+k)));
        }
        return dp[i][currtakemax]=maxi;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int sum=0;
        int n=piles.size();
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
        }
        dp=vector<vector<int>>(n,vector<int>(2*n,-1));
        int diff=stone(piles,0,1);
        return (sum+diff)/2;
    }
};