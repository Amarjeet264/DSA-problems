class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int amount=0;
        int i=piles.size()-2;
        int per=piles.size()/3;
        while(i>=per){
            amount+=piles[i];
            i=i-2;
        }
        return amount;
    }
};