class Solution {
    int initial;
    vector<vector<int>> dp; // Memoization table

    int shelves(vector<vector<int>>& books, int W, int i, int maxHeight) {
        if (i >= books.size()) {
            return maxHeight;
        }
        if (dp[i][W] != -1) {
            return dp[i][W];
        }

        int keep = INT_MAX, skip = INT_MAX;

        // If we can keep the book on the current shelf
        if (books[i][0] <= W) {
            keep = shelves(books, W - books[i][0], i + 1, max(maxHeight, books[i][1]));
        }

        // If we skip to a new shelf
        skip = maxHeight + shelves(books, initial - books[i][0], i + 1, books[i][1]);

        return dp[i][W] = min(keep, skip);
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int W) {
        initial = W;
        dp.resize(books.size(), vector<int>(W + 1, -1));
        return shelves(books, W, 0, 0);
    }
};
