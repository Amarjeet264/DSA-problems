#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 0));

        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mod = (nums[i] + nums[j]) % k;
                dp[j][mod] = dp[i][mod] + 1;
                maxi = max(maxi, dp[j][mod]);
            }
        }

        return maxi+1 ; 
    }
};
