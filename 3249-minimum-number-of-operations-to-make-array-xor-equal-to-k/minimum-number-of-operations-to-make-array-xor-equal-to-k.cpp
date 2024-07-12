class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int all = nums[0];
        for(int i=1;i<nums.size();i++){
            all ^= nums[i];
        }
        return __builtin_popcount(all^k);
    }
};