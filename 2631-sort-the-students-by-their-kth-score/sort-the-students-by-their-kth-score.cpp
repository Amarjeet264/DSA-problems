class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<int>vec(score.size());
        for(int i=0;i<score.size();i++){
            vec[i] = score[i][k];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<vec.size();i++){
            mp[vec[i]] = i;
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>>ans=score;
        for(int i=0;i<score.size();i++){
            // cout<<vec[i]<<" ";
            ans[i]=score[mp[vec[score.size()-i-1]]];
        }
        return ans;
    }
};