class Solution {
    bool isposs(int p,vector<int>&nums,int diff){
        int i=0;
        int n=nums.size();
        while(i<n-1){
            if(nums[i+1]-nums[i]<=diff){
                p--;
                i+=2;
            }
            else{
                i++;
            }
        }
        return p<=0;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int high=nums[n-1]-nums[0];
        int low=0;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(isposs(p,nums,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};