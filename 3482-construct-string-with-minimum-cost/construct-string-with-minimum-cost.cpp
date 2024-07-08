class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    long long cost=LLONG_MAX;
};

class Solution {
    TrieNode* root;

    void insert(string& word, long long cost) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->cost = min(node->cost, cost); // Update the cost to the minimum one
    }

    long long call(string& target, int i, vector<long long>& dp) {
        if (i == target.size()) {
            return 0;
        }
        if (i > target.size()) {
            return 1e12;
        }
        if (dp[i] != -1) return dp[i];
        long long mini = 1e12;
        TrieNode* node = root;
        for (int j = i; j < target.size(); j++) {
            if (node->children.find(target[j]) == node->children.end()) break;
            node = node->children[target[j]];
            if (node->cost != LLONG_MAX) {
                long long take = node->cost + call(target, j + 1, dp);
                mini = min(mini, take);
            }
        }
        return dp[i] = mini;
    }

public:
    long long minimumCost(string target, vector<string>& words, vector<int>& costs) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            insert(words[i], (long long)costs[i]);
        }
        vector<long long> dp(target.size(), -1);
        long long x = call(target, 0, dp);
        if (x >= 1e12) return -1;
        return x;
    }
};
