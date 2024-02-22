class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>ans;
        int cnt=1;
        int idx=0;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                cnt++;
            }
            else{
                if(cnt>=3){
                    ans.push_back({idx,i-1});
                }
                cnt=1;
                idx=i;
            }
        }
        int n=s.size();
        if(cnt>=3){
            ans.push_back({idx,n-1});
        }
        return ans;
    }
};