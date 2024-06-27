class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(), ' '); // Create a string with the same size as s, initialized with spaces.
        for(int i = 0; i < indices.size(); ++i) {
            ans[indices[i]] = s[i]; // Place each character at the correct index.
        }
        return ans;
    }
};
