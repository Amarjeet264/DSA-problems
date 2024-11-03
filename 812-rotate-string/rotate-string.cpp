class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string doubled = s + s;
        return kmpSearch(doubled, goal);
    }

private:
    bool kmpSearch(const string& text, const string& pattern) {
        vector<int> lps = computeLPSArray(pattern);
        int i = 0; // index for text
        int j = 0; // index for pattern
        int m = text.size();
        int n = pattern.size();

        while (i < m) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == n) return true; // found match
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return false;
    }

    vector<int> computeLPSArray(const string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;

        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }
};
