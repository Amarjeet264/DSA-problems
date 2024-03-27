class Solution {
    int call(vector<vector<vector<int>>>& dp, vector<string>& words, char first, char last, int i) {
        if (i >= words.size()) {
            return 0;
        }
        if (dp[i][first - 'a'][last - 'a'] != -1) {
            return dp[i][first - 'a'][last - 'a'];
        }
        string curr = words[i];
        int fr = 0;
        int la = 0;
        if (last == curr[0]) {
            fr = curr.size() - 1 + call(dp, words, first, curr[curr.size() - 1], i + 1);
        } else {
            fr = curr.size() + call(dp, words, first, curr[curr.size() - 1], i + 1);
        }
        if (curr[curr.size() - 1] == first) {
            la = curr.size() - 1 + call(dp, words, curr[0], last, i + 1);
        } else {
            la = curr.size() + call(dp, words, curr[0], last, i + 1);
        }
        return dp[i][first - 'a'][last - 'a'] = min(la, fr);
    }
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<vector<int>>> dp(words.size(), vector<vector<int>>(26, vector<int>(26, -1)));
        return words[0].size() + call(dp, words, words[0][0], words[0][words[0].size() - 1], 1);
    }
};
