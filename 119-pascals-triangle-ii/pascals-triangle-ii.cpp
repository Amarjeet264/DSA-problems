class Solution {
public:
    vector<int> getRow(int row) {
        vector<int>ans;
        ans.push_back(1);
        for(int i=1;i<=row;i++){
            vector<int>dup;
            dup.push_back(ans[0]);
            for(int j=0;j<ans.size()-1;j++){
                dup.push_back(ans[j]+ans[j+1]);
            }
            dup.push_back(ans[ans.size()-1]);
            ans=dup;
        }
        return ans;
    }
};