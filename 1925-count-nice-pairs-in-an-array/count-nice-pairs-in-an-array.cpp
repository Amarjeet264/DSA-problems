class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mod=1e9+7;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            long long a=nums[i];
            long long reva=-1;
            string s=to_string(nums[i]);
            reverse(s.begin(),s.end());
            reva=stoi(s);
            ans+=mp[a-reva]%mod;
            mp[a-reva]++;
        }
        return ans%mod;
    }
};