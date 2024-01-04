class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> mp;
        
        // Count occurrences of each element
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        while (!mp.empty()) {
            vector<int> dup;
            vector<int> elementsToRemove;

            for (auto& it : mp) {
                int ele = it.first;
                dup.push_back(ele);
                it.second--;

                if (it.second == 0) {
                    elementsToRemove.push_back(ele);
                }
            }

            for (int ele : elementsToRemove) {
                mp.erase(ele);
            }

            ans.push_back(dup);
        }

        return ans;
    }
};
