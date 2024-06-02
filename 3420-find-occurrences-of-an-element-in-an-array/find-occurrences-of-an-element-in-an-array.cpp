class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int>mp;
        int count=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x)mp[count++]=i;
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            if(mp.find(queries[i])==mp.end()){
                ans[i]=-1;
            }
            else{
                ans[i]=mp[queries[i]];
            }
        }
        return ans;
    }
};