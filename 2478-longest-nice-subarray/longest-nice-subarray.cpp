class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int x=nums[0];
        int i=0;
        int j=1;
        int maxi=1;
        while(j<nums.size()){
            while(i<=j&&(nums[j]&x)){
                x=x^nums[i];
                i++;
                maxi=max(maxi,j-i+1);
            }
            x=x|nums[j];
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};