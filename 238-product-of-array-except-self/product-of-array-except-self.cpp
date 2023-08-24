class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int prod=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }
        }
        vector<int>ans(nums.size(),0);
        if(zero>1){
            return ans;
        }
        if(zero==1){
            int idx=-1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    prod=prod*nums[i];
                }
                else{
                    idx=i;
                }
            }
            ans[idx]=prod;
            return ans;
        }
        prod=1;
        for(int i=0;i<nums.size();i++){
            prod=prod*nums[i];
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=prod/nums[i];
        }
        return ans;
    }
};