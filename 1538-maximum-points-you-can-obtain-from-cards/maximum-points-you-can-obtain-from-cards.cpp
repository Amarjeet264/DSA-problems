class Solution {
    // int maxii(int i,vector<int>&cards,int k,int j,vector<int>dp){
    //     if(k<=0){
    //         return 0;
    //     }
    //     if(i>j){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int x=cards[i]+maxii(i+1,cards,k-1,j,dp);
    //     int y=cards[j]+maxii(i,cards,k-1,j-1,dp);
    //     return dp[i][j]= max(x,y);
    // }
public:
    int maxScore(vector<int>& cards, int k) {
        int amount=0;
        int i=0;
        int c=k;
       while(c>=1&&i<cards.size()){
           amount+=cards[i];
           i++;
           c--;
       }
       int maxi=amount;
       int j=cards.size()-1;
       i=k-1;
       while(i>=0&&j>i){
            amount=amount-cards[i]+cards[j];
            maxi=max(maxi,amount);
            j--;
            i--;
       }
       return maxi;
    }
};