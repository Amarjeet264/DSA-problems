class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long i = 0;
        long long j = 0;
        long long ans = 0;
        long long prod = 0;
        while(j<nums.size()){
            prod = prod + nums[j];
            while(prod*(j-i+1) >= k){
                prod = prod - nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};