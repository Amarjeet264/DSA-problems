class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        while(mp.size()>0){
            vector<int>dup;
            vector<int>rem;
            for(auto it:mp){
                int ele=it.first;
                dup.push_back(ele);
                mp[ele]--;
                if(mp[ele]==0){
                    rem.push_back(ele);
                }
            }
            for(auto x:rem){
                mp.erase(x);
            }
            ans.push_back(dup);
        }
        return ans;
    }
};