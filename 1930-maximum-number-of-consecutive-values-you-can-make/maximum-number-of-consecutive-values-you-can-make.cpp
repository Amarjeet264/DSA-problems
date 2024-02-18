class Solution {
public:
    int getMaximumConsecutive(vector<int>&coins) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int sum=0;
        int i=0;
        while(i<n){
            if(sum+1<coins[i]){
                return sum+1;
            }
            sum+=coins[i];
            i++;
        }
        return sum+1;
    }
};