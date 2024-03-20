class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i = 0; i < arr.size(); ++i) {
            int remainder = arr[i] % k;
            if (remainder < 0) {
                remainder += k; // Ensure remainder is positive
            }
            int complement = (k - remainder) % k; // Find complement
            if(mp.find(complement) != mp.end()) {
                mp[complement]--;
                if(mp[complement] == 0) {
                    mp.erase(complement);
                }
            } else {
                mp[remainder]++;
            }
        }
        return mp.empty();
    }
};
