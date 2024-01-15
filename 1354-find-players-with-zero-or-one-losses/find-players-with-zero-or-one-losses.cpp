class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        ans.push_back({});
        ans.push_back({});
        map<int,int>mp;
        map<int,int>mp1;
        for(int i=0;i<matches.size();i++){
            mp[matches[i][1]]++;
            // mp1[matches[i][1]]++;
            mp1[matches[i][0]]++;
        }
        for(auto it:mp1){
             if(mp.find(it.first)==mp.end()){
                ans[0].push_back(it.first);
            }
        }
        for(auto it:mp){
             if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};