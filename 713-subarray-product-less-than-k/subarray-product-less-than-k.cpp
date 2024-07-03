class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long i = 0;
        long long j = 0;
        long long ans = 0;
        long long prod = 1;
        while(j<nums.size()){
            prod = prod * nums[j];
            while(i<=j&&prod >= k){
                prod = prod / nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};