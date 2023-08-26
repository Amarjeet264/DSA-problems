class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]==1?1:-1;
            if(mp.find(sum)!=mp.end()){
                maxi=max(maxi,i-mp[sum]+1);
                continue;
            }
            mp[sum]=i+1;
        }
        return maxi;
    }
};