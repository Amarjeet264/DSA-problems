#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    vector<vector<int>> memo;

    int value(int i, int k, vector<vector<int>>& piles) {
        if (i >= piles.size() || k == 0) {
            return 0;
        }
        if (memo[i][k] != -1) {
            return memo[i][k];
        }
        int notTake = value(i + 1, k, piles);
        int take = 0;
        int currentSum = 0;
        for (int j = 0; j < min((int)piles[i].size(), k); ++j) {
            currentSum += piles[i][j];
            take = max(take, currentSum + value(i + 1, k - (j + 1), piles));
        }
        return memo[i][k] = max(take, notTake);
    }

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memo = vector<vector<int>>(piles.size(), vector<int>(k + 1, -1));
        return value(0, k, piles);
    }
};
