class Solution {
    vector<vector<int>>dp;
    bool stone(int i,int j,vector<int>&piles,int krishna,int radha,bool cankrishna){
        if(i>=j){
            return krishna>radha;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(cankrishna){
            return dp[i][j]= stone(i+1,j,piles,krishna+piles[i],radha,0)||stone(i,j-1,piles,krishna+piles[j],radha,0);
        }
        else
          return dp[i][j]= stone(i+1,j,piles,krishna,radha+piles[i],1)||stone(i,j-1,piles,krishna,radha+piles[j],1);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        return true;
    }
};