class Solution {
    int call(vector<vector<vector<int>>>& dp, vector<string>& words, int first, int last, int i) {
        if (i >= words.size()) {
            return 0;
        }
        if (dp[i][first][last] != -1) {
            return dp[i][first][last];
        }
        string curr = words[i];
        int fr = 0;
        int la = 0;
        if (last == curr[0]-'a') {
            fr = curr.size() - 1 + call(dp, words, first, curr[curr.size() - 1]-'a', i + 1);
        } else {
            fr = curr.size() + call(dp, words, first, curr[curr.size() - 1]-'a', i + 1);
        }
        if (curr[curr.size() - 1]-'a' == first) {
            la = curr.size() - 1 + call(dp, words, curr[0]-'a', last, i + 1);
        } else {
            la = curr.size() + call(dp, words, curr[0]-'a', last, i + 1);
        }
        return dp[i][first][last] = min(la, fr);
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<vector<int>>> dp(words.size(), vector<vector<int>>(26, vector<int>(26, -1)));
        return words[0].size() + call(dp, words, words[0][0]-'a', words[0][words[0].size() - 1]-'a', 1);
    }
};
