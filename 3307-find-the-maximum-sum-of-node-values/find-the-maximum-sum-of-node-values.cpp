class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long idealSum = 0 ;
        int minNuk = INT_MAX;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int ifxor = nums[i] ^ k;
            if(ifxor>nums[i]){
                idealSum += ifxor;
                cnt++;
            }
            else{
                idealSum += nums[i];
            }
            minNuk = min(minNuk,abs(nums[i]-ifxor));
        }
        if(cnt%2){
            idealSum -= minNuk;
        }
        return idealSum;
    }
};