class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n1;i++){
            mp[nums1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<n2;i++){
            if(mp.find(nums2[i])!=mp.end()){
                ans.push_back(nums2[i]);
                mp.erase(nums2[i]);
            }
        }
        return ans;
    }
};