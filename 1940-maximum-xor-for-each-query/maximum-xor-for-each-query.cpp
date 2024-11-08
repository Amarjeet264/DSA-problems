class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxB) {
        int maxi = pow(2,maxB)-1;
        int tot = nums[0];
        for(int i=1;i<nums.size();i++){
            tot = tot^nums[i];
        }
        vector<int>ans;
        int j = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            ans.push_back(tot^maxi);
            tot = tot^nums[j];
            j--;
        }
        return ans;
    }
};