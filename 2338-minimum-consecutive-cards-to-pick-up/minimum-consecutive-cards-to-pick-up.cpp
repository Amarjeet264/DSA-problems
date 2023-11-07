class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int i=0;
        int j=0;
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        while(j<cards.size()){
            mp[cards[j]]++;
            if(mp.size()<j-i+1){
                while(i<j&&mp.size()<j-i+1){
                    ans=min(ans,j-i+1);
                    mp[cards[i]]--;
                    if(mp[cards[i]]==0){
                        mp.erase(cards[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};