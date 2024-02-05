#include <vector>
#include <algorithm>

class Solution {
public:
    int maxRotateFunction(std::vector<int>& nums) {
        int n = nums.size();

        // Calculate the initial sum and F(0)
        int sum = 0;
        int rotationSum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            rotationSum += i * nums[i];
        }

        int maxRotationSum = rotationSum;
        for (int k = 1; k < n; ++k) {
            rotationSum = rotationSum + sum - n * nums[n - k];

            // Update the maximum rotation sum
            maxRotationSum = std::max(maxRotationSum, rotationSum);
        }

        return (maxRotationSum);
    }
};
