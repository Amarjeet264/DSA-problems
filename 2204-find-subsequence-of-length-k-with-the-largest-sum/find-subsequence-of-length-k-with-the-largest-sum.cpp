class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.rbegin(),vec.rend());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++){
            ans[i]=nums[ans[i]];
        }
        return ans;
    }
};