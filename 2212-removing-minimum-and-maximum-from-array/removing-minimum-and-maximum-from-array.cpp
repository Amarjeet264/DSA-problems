class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int n=nums.size();
        if(n<=1){
            return n;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            if(nums[i]<mini){
                mini=nums[i];
            }
        }
        int first_maxidx=-1;
        int first_minidx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                first_maxidx=i;
            }
            if(nums[i]==mini){
                first_minidx=i;
            }
        }
        if(first_maxidx<first_minidx){
            return min(first_maxidx+n-first_minidx+1,min(first_minidx+1,n-first_maxidx));
        }
        return min(first_minidx+n-first_maxidx+1,min(first_maxidx+1,n-first_minidx));
    }
};