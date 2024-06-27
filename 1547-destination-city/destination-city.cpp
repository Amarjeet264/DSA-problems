class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mp;
        for(auto it:paths){
            mp[it[0]]++;
            mp[it[1]]++;
        }
        for(auto it:paths){
            // mp[it[0]]--;
            mp.erase(it[0]);
        }
        if(mp.size()==0){
            return "";
        }
        string ans="";
        for(auto it:mp){
            ans=it.first;
        }
        return ans;
    }
};