class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long>ans;
        multiset<long long>st;
        unordered_map<long long,long long>mp;
        for(int i=0;i<nums.size();i++){
            long long x=mp[nums[i]];
            if(mp[nums[i]]!=0){
                st.erase(st.find(mp[nums[i]]));
            }
            mp[nums[i]]+=freq[i];
            st.insert(x+freq[i]);
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};