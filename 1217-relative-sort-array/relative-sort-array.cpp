class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<arr2.size();i++){
            int x=mp[arr2[i]];
            while(x--){
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        vector<int>ans1;
        for (auto it = mp.begin(); it != mp.end(); ) {
            int x = it->second;
            while (x--) {
                ans1.push_back(it->first);
            }
            it = mp.erase(it);  // Update the iterator after erasing
        }
        sort(ans1.begin(),ans1.end());
        for(auto it:ans1){
            ans.push_back(it);
        }
        return ans;
    }
};