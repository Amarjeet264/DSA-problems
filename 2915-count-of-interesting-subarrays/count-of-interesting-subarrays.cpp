class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<long long,long long>mp;
        int i=0;
        int j=0;
        long long ans=0;
        long long cnt=0;
        mp[0]=1;
        while(j<nums.size()){
            if(nums[j]%modulo==k){
                cnt++;
            }
            ans+=mp[(-k+(cnt%modulo)+modulo)%modulo];
            mp[cnt%modulo]++;
            j++;
        }
        return ans;
    }
};