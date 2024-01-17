class Solution {
    bool isposs(int mid,vector<int>&nums,int maxo){
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid){
                // cout<<mid<<" ";
                maxo=maxo-((ceil)(nums[i]/(double)mid)-1);
                if(maxo<0){
                    return 0;
                }
            }
        }
        return 1;

    }
public:
    int minimumSize(vector<int>& nums, int maxo) {
        sort(nums.begin(),nums.end());
        int low=1;
        int high=nums[nums.size()-1];
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isposs(mid,nums,maxo)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};