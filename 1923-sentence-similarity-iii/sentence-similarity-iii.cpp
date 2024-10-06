class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Split both sentences into words
        vector<string> words1 = splitWords(s1);
        vector<string> words2 = splitWords(s2);
        
        // Ensure words1 is the shorter sentence
        if (words1.size() > words2.size()) swap(words1, words2);
        
        int i = 0, j = 0;
        int n = words1.size(), m = words2.size();
        
        // Match the prefix of both sentences
        while (i < n && words1[i] == words2[i]) i++;
        
        // Match the suffix of both sentences
        while (j < n && words1[n - 1 - j] == words2[m - 1 - j]) j++;
        
        // If the number of unmatched words in the longer sentence (words2) is exactly one, return true
        return i + j >= n;
    }

private:
    // Utility function to split a sentence into words
    vector<string> splitWords(string &sentence) {
        vector<string> result;
        string word;
        stringstream ss(sentence);
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }
};
