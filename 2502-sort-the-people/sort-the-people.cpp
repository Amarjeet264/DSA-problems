class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        
        unordered_map<int,string> mpp;
        
        for(int i=0;i<names.size();i++){
            mpp[heights[i]]=names[i];
        }
        
        sort(heights.rbegin(),heights.rend());
        
        for(int i=0;i<heights.size();i++){
            ans.push_back(mpp[heights[i]]);
        }
        
        return ans;
    }
};