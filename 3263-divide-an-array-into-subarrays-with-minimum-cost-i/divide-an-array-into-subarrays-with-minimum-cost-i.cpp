class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=nums[0];
        vector<int>x;
        for(int i=1;i<nums.size();i++){
            x.push_back(nums[i]);
        }
        sort(x.begin(),x.end());
        return sum+x[0]+x[1];
    }
};