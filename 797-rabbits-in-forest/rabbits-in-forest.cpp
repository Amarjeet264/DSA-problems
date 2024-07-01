class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count = 0;
        // Initialize map
        int n=answers.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
    
            // Add to the count if not found or
            // has exhausted the count of all the
            // number of rabbits of same colour
            if (mp[answers[i]] == 0) {
                count += answers[i] + 1;
                mp[answers[i]] = answers[i] + 1;
            }
            mp[answers[i]]--;
        }
    
        // count gives minimum number
        // of rabbits in the forest
        return count;
    }
};