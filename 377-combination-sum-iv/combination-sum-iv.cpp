class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<double>dp(target+1);
        dp[0]=1;
        int mod=1e9+7;
        for(int i=1;i<dp.size();i++){
            for(int j=0;j<n;j++){
                if(i>=nums[j])(dp[i]+=dp[(double)i-(double)nums[j]]);
            }
        }
        return (int)dp[target];
    }
};