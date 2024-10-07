struct Node {
    bool end = 0;
    Node* Links[26] = {nullptr};

    bool containsKey(char ch) { return Links[ch - 'a'] != nullptr; }

    void put(char ch, Node* node) { Links[ch - 'a'] = node; }

    Node* next(char ch) { return Links[ch - 'a']; }

    bool isEnd() { return end; }

    void setEnd() { end = 1; }
};

class TrieNode {
    Node* root;

public:
    TrieNode() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsKey(word[i])) {
                curr->put(word[i], new Node());
            }
            curr = curr->next(word[i]);
        }
        curr->setEnd();
    }

    int count(string word, int i, vector<int>& dp) {
        if (i == word.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int ans = -1e9;
        Node* curr = root;
        for (int j = i; j < word.size(); j++) {
            if (!curr->containsKey(word[j])) {
                break;
            }
            curr = curr->next(word[j]);
            if (curr->isEnd()) {
                ans = max(ans, 1 + count(word, j + 1, dp));
            }
        }
        return dp[i] = ans;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TrieNode trie;
        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i]);
        }

        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            vector<int> dp(words[i].size(), -1);
            if (trie.count(words[i], 0, dp) >= 2) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};