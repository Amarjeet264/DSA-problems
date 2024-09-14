class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxAns = 0;
        int prev = INT_MIN;
        for(auto it:mp){
            if(prev!=INT_MIN&&it.first-prev==1){
                maxAns = max(maxAns,mp[prev]+it.second);
            }
            prev = it.first;
        }
        return maxAns;
    }
};