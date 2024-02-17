class Solution {
    set<vector<int>>st;
    void find(vector<int>&temp,int i,vector<int>&nums){
        if(i>=nums.size()){
            if(temp.size()>1){
                st.insert(temp);
            }
            return;
        }
        find(temp,i+1,nums);
        if(temp.size()==0||nums[i]>=temp.back()){
            temp.push_back(nums[i]);
            find(temp,i+1,nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        find(temp,0,nums);
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};