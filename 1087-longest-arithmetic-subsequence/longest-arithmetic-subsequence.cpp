#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int longest = 2; // the minimum length of an arithmetic sequence is 2
        vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i]; // diff is now nums[j] - nums[i]
                if (dp[i].count(diff)) {
                    dp[j][diff] = dp[i][diff] + 1;
                } else {
                    dp[j][diff] = 2; // the initial length of the sequence is 2
                }
                longest = max(longest, dp[j][diff]);
            }
        }

        return longest;
    }
};
