class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int>ans(accounts.size());
        for(int i=0;i<accounts.size();i++){
            for(int j=0;j<accounts[0].size();j++){
                ans[i]+=accounts[i][j];
            }
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};