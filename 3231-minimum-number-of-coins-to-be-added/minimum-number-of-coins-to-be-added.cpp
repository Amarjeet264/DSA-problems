class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int sum=0;
        int cnt=0;
        int i=0;
        while(sum<target){
            if(i<n&&coins[i]<=sum+1){
                sum+=coins[i];
                i++;
            }
            else{
                sum+=sum+1;
                cnt++;
            }
        }
        return cnt;
    }
};