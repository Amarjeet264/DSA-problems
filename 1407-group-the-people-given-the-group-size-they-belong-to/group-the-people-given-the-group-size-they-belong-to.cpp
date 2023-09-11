class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        unordered_map<int,vector<int>>mp;
        vector<vector<int>>ans;
        for(int i=0;i<group.size();i++){
            if(mp.find(group[i])==mp.end()||mp[group[i]].size()<group[i]){
                mp[group[i]].push_back(i);
            }
            else{
                ans.push_back(mp[group[i]]);
                mp.erase(group[i]);
                mp[group[i]].push_back(i);
            }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};