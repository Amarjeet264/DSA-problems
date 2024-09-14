class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = nums[0];
        for(int i =0;i<nums.size();i++){
            maxEle = max(maxEle,nums[i]);
        }
        int maxLen = 1;
        int cnt = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]==nums[i-1]&&nums[i]==maxEle){
                cnt++;
                maxLen = max(maxLen,cnt);
            }
            else{
                cnt = 1;
            }
        }
        return maxLen;
    }
};