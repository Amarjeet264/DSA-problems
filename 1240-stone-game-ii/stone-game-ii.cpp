class Solution {
//     vector<vector<vector<int>>>dp;
//     int stone(vector<int>&pre,vector<int>&piles,int i,int currtakemax,bool can){
//         if(i>=piles.size()){
//             return 0;
//         }
//         int maxi=0;
//         int alice=INT_MAX;
//         for(int k=0;k<2*currtakemax;k++){
//             if(can){
//                 if(i+k<piles.size()){
//                     maxi=max(maxi,pre[i+k]+stone(pre,piles,i+k+1,max(currtakemax,k+1),0));
//                 }
//             }
//             else{
//                 alice=min(alice,stone(pre,piles,i+k+1,max(currtakemax,k+1),1));
//             }
//         }
//         return can?maxi:alice;
//     }
// public:
//     int stoneGameII(vector<int>& piles) {
//         int sum=0;
//         int n=piles.size();
//         vector<int>pre;
//         dp=vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(2,-1)));
//         for(int i=0;i<n;i++){
//             sum+=piles[i];
//             pre.push_back(sum);
//         }
//         return stone(pre,piles,0,1,1);
//     }
vector<vector<vector<int>>>dp;
    int getPrefix(int start,int size,vector<int>&prefix){
        int end=prefix.size()-1;
        if(start+size<prefix.size())
            end=start+size-1;
        return start? prefix[end]-prefix[start-1]: prefix[end];
     }
    int stone(vector<int>&pre,vector<int>&piles,int i,int currtakemax,bool can){
        if(i>=piles.size()){
            return 0;
        }
        int maxi=0;
        int alice=INT_MAX;
        if(dp[i][currtakemax][can]!=-1)return dp[i][currtakemax][can];
        for(int k=0;k<2*currtakemax;k++){
            if(can){
                if(i+k<piles.size()){
                    maxi=max(maxi,getPrefix(i,k+1,pre)+stone(pre,piles,i+k+1,max(currtakemax,k+1),0));
                }
            }
            else{
                alice=min(alice,stone(pre,piles,i+k+1,max(currtakemax,k+1),1));
            }
        }
        return dp[i][currtakemax][can]= can?maxi:alice;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int sum=0;
        int n=piles.size();
        vector<int>pre;
        for(int i=0;i<n;i++){
            sum+=piles[i];
            pre.push_back(sum);
        }
        dp=vector<vector<vector<int>>>(n,vector<vector<int>>(2*n,vector<int>(2,-1)));
        return stone(pre,piles,0,1,1);
    }
};