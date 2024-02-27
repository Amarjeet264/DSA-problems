class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=INT_MIN;
        if(n<2)return 0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,nums[i+1]-nums[i]);
        }
        return maxi;
    }
};