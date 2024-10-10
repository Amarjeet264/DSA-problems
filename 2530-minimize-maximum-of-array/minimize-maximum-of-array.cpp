class Solution {
    bool isposs(long long mid,vector<long long>nums){
        long long buff = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid&&nums[i]-mid>buff){
                return 0;
            }
            nums[i] = nums[i] - buff;
            buff = mid - nums[i];
        }
        return 1;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long low = 1e12;
        long long high = -1e12;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<low){
                low = nums[i];
            }
            if(nums[i]>high){
                high = nums[i];
            }
        }
        int ans = -1;
        vector<long long>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back((long long)nums[i]);
        }
        while(low<=high){
            long long mid = (low+high)/2;
            if(isposs(mid,arr)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};