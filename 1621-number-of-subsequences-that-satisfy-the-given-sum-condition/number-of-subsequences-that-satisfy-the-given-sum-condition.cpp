class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int mod=1e9+7;
        int ans=0;
        vector<int>power(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            power[i]=power[i-1]*2%mod;
        }
        while(i<=j){
            if(nums[j]+nums[i]<=target){
                ans=(ans+(int)power[j-i])%mod;
                i++;
            }
            else{
                j--;
            }
        }
        return ans%mod;
    }
};