class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x>=k)return 1;
            for(int j=i+1;j<n;j++){
                x=x|nums[j];
                if(x>=k)mini=min(mini,j-i+1);
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};