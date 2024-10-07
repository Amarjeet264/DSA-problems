struct Node {
    bool end = 0;
    Node* Links[26] = {nullptr};  // Initialize with nullptrs

    bool containsKey(char ch) {
        return Links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        Links[ch - 'a'] = node;
    }

    Node* next(char ch) {
        return Links[ch - 'a'];
    }

    bool isEnd() {
        return end;
    }

    void setEnd() {
        end = 1;
    }
};

class TrieNode {
    Node* root;
public:
    TrieNode() {
        root = new Node();
    }

    void insert(std::string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsKey(word[i])) {
                curr->put(word[i], new Node());
            }
            curr = curr->next(word[i]);
        }
        curr->setEnd();
    }
    
    bool count(std::string word, int i, int parts,vector<vector<int>>&dp) {
        if (i == word.size()) {
            return parts >= 2;  // Word must be formed by at least two parts
        }
        if(dp[i][parts]!=-1){
            return dp[i][parts];
        }
        Node* curr = root;
        for (int j = i; j < word.size(); j++) {
            if (!curr->containsKey(word[j])) {
                return dp[i][parts] = false;
            }
            curr = curr->next(word[j]);
            if (curr->isEnd()) {
                // Try to split here and count further parts
                if (count(word, j + 1, parts + 1,dp)) {
                    return dp[i][parts] = true;
                }
            }
        }
        return dp[i][parts] = false;
    }
};

class Solution {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        TrieNode trie;
        // Insert all words into the Trie
        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i]);
        }

        std::vector<std::string> ans;
        // Check if each word can be formed by concatenating two or more words
        for (int i = 0; i < words.size(); i++) {
            vector<vector<int>>dp(words[i].size(),vector<int>(words[i].size(),-1));
            if (trie.count(words[i], 0, 0,dp)) {

                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
