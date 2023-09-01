// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
        
//     }
//     #include <queue>
// #include <vector>
// #include <algorithm>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::multiset<int> minSet;
        std::multiset<int, std::greater<int>> maxSet;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int len = 0;
        
        while (j < n) {
            minSet.insert(nums[j]);
            maxSet.insert(nums[j]);
            
            while (i < j && *maxSet.begin() - *minSet.begin() > limit) {
                minSet.erase(minSet.find(nums[i]));
                maxSet.erase(maxSet.find(nums[i]));
                i++;
            }
            
            j++;
            len = std::max(len, j - i);
        }
        
        return len;
    }
};

// };