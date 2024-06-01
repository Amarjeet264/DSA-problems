class Solution {
    void subset(int i,vector<int>dup,vector<int>&nums,vector<vector<int>>&ans,int n){
        if(i==n){
            ans.push_back(dup);
            return;
        }
        subset(i+1,dup,nums,ans,n);
        dup.push_back(nums[i]);
        subset(i+1,dup,nums,ans,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>dup;
        subset(0,dup,nums,ans,nums.size());
        return ans;
    }
};