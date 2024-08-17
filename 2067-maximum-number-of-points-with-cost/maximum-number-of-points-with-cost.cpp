class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();      // number of rows
        int m = points[0].size();   // number of columns

        // Create a DP table where dp[row][col] stores the max points obtainable starting from row to the end
        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        // Initialize the last row in dp to the values in the last row of points
        for (int col = 0; col < m; ++col) {
            dp[n-1][col] = points[n-1][col];
        }

        // Fill the DP table from the second last row to the top
        for (int row = n-2; row >= 0; --row) {
            // To optimize the transition, use two passes: 
            // one from left to right and another from right to left
            vector<long long> left(m, 0), right(m, 0);

            // Fill left: max value we can get if we start from the leftmost column
            left[0] = dp[row+1][0];
            for (int col = 1; col < m; ++col) {
                left[col] = max(left[col-1] - 1, dp[row+1][col]);
            }

            // Fill right: max value we can get if we start from the rightmost column
            right[m-1] = dp[row+1][m-1];
            for (int col = m-2; col >= 0; --col) {
                right[col] = max(right[col+1] - 1, dp[row+1][col]);
            }

            // Calculate the dp values for the current row
            for (int col = 0; col < m; ++col) {
                dp[row][col] = points[row][col] + max(left[col], right[col]);
            }
        }

        // The result will be the maximum value in the first row of dp
        long long maxi = 0;
        for (int col = 0; col < m; ++col) {
            maxi = max(maxi, dp[0][col]);
        }

        return maxi;
    }
};
