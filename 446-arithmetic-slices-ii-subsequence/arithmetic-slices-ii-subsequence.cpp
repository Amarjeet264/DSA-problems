class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        map<pair<int,long long>,int>dp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)nums[i]-(long long)nums[j];
                dp[{i,diff}]++;
                if(dp.find({j,diff})!=dp.end()){
                    dp[{i,diff}]+=dp[{j,diff}];
                    ans+=dp[{j,diff}];
                }
            }
        }
        return ans;
    }
};