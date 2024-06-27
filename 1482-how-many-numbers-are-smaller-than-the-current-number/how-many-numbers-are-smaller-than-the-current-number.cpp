class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>vec=nums;
        sort(nums.begin(),nums.end());
        int cnt=0;
        // int prev=nums[0];
        vector<int>ans(nums.size());
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                mp[nums[i]]=i;
                // cnt++;
            }
            else{
                cnt++;
            }
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=mp[vec[i]];
        }
        return ans;
    }
};