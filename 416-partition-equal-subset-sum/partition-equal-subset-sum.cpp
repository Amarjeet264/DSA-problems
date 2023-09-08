class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2)return false;
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(j==0){
                    dp[i][j]=1;
                }
                else if(i>0){
                    if(j>=arr[i-1]){
                        dp[i][j]=dp[i][j]||dp[i-1][j-arr[i-1]];
                    }
                    dp[i][j]=dp[i][j]||dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};