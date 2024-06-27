class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            nums.push_back(stoi(s));
        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        return mp.size();
    }
};