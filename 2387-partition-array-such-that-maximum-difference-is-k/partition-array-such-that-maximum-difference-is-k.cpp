class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=1;
        int cnt=1;
        int mini=nums[0];
        while(i<nums.size()){
            if(nums[i]-mini<=k){
                i++;
            }
            else{
                mini=nums[i];
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};