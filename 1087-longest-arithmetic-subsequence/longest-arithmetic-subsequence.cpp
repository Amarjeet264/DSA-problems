class Solution {
    // int solveback(int diff,int i,vector<int>&nums,int ele,unordered_map<int,int>dp[]){
    //     if(i<0){
    //         return 0;
    //     }
    //     if(dp[i].count(diff)){
    //         return dp[i][diff];
    //     }
    //     if(ele-nums[i]==diff){
    //         return dp[i][diff]=1+solveback(diff,i-1,nums,nums[i],dp);
    //     }
    //     return dp[i][diff]=solveback(diff,i-1,nums,ele,dp);
    // }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int longest = 2;
        vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                longest = max(longest, dp[i][diff]);
            }
        }

        return longest;
    }
};