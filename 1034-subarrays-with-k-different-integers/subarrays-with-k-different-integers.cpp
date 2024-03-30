class Solution {
    int countdist(vector<int>&nums,int k){
        int  i=0;
        int j=0;
        unordered_map<int,int>mp;
        int ans=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countdist(nums,k)-countdist(nums,k-1);
    }
};