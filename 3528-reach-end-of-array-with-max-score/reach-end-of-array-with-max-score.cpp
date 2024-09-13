class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        long long temp=nums[0];
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp || i==nums.size()-1){
                ans= ans + ((i-j)*temp);
                temp=nums[i];
                j=i;
            }
        }
        return ans;
    }
};