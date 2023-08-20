class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int maxi=0;
        unordered_map<int,int>mp;
        int most=0;
        while(j<nums.size()){
            most=max(most,++mp[nums[j]]);
            while(j-i-most>=k){
                mp[nums[i]]--;
                i++;
            }
            maxi=max(maxi,most);
            j++;
        }
        return maxi;
    }
};