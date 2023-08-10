class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[low]&&nums[low]==nums[high]){
                low++;
                high--;
            }
            else if(nums[mid]>=nums[low]){
                if(target<nums[mid]&&target>=nums[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target>nums[mid]&&target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};