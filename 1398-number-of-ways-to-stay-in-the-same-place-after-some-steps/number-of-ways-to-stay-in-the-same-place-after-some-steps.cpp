class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int mod = 1000000007;
        int maxPosition = min(steps / 2, arrLen - 1);
        vector<vector<int>> dp(steps + 1, vector<int>(maxPosition + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxPosition; j++) {
                dp[i][j] = dp[i - 1][j];
                
                if (j > 0) {
                    dp[i][j] = (dp[i][j]%mod + dp[i - 1][j - 1]%mod) % mod;
                }
                if (j < maxPosition) {
                    dp[i][j] = (dp[i][j]%mod + dp[i - 1][j + 1]%mod) % mod;
                }
            }
        }
        return dp[steps][0];
    }
};