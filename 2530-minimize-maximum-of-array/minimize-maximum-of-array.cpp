class Solution {
    bool isposs(long long mid,vector<int>arr){
        vector<long long>nums ;
        for(int i=0;i<arr.size();i++){
            nums.push_back((long long)arr[i]);
        }
        long long buff = 0;
        for(int i=0;i<nums.size()-1;i++){
            // if(nums[i]>mid&&nums[i]-mid>buff){
            //     return 0;
            // }
            // nums[i] = nums[i] - buff;
            // if(nums[i]<0){
            //     nums[i] = 0;
            // }
            // buff = mid - nums[i];
            if(nums[i]>mid)return 0;
            buff = mid-nums[i];
            nums[i+1] = nums[i+1]-buff;
        }
        return nums[nums.size()-1]<=mid;
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
        while(low<=high){
            long long mid = (low+high)/2;
            if(isposs(mid,nums)){
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