class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<=0){
            return {};
        }
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        }
        int maxidx=0;
        int maxi=1;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(maxi<dp[i]){
                maxi=dp[i];
                maxidx=i;
            }
        }
        while(hash[maxidx]!=maxidx){
            ans.push_back(nums[maxidx]);
            maxidx=hash[maxidx];
        }
        if(maxidx>=0){
            ans.push_back(nums[maxidx]);
        }
        return ans;
    }
};