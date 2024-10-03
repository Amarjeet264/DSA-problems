class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int k=sum%p;
        long long x=0;
        if(k==0) return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
            int rem=x%p;
            int r=(rem-k+p)%p;
            if(mp.find(r)!=mp.end())mini=min(mini,i-mp[r]);
            mp[rem]=i;
        }
        if(mini==nums.size()) return -1;
        return mini;
    }
};