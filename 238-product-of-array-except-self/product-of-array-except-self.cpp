class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int prod=1;
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                idx=i;
                zero++;
            }
        }
        vector<int>ans(nums.size(),0);
        if(zero>1){
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                prod=prod*nums[i];
            }
        }
        if(zero==1){  
            ans[idx]=prod;
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=prod/nums[i];
        }
        return nums;
    }
};