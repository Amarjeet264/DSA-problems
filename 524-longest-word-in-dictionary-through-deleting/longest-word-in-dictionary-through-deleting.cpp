class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        string ans="";
        for(int i=0;i<dict.size();i++){
            int j=0;
            int k=0;
            while(j<dict[i].size()&&k<s.length()){
                if(dict[i][j]==s[k]){
                    j++;
                    k++;
                }
                else{
                    k++;
                }
            }
            if(j==dict[i].size()){
                if(ans.size()<dict[i].size()){
                    ans=dict[i];
                }
                else if(ans.size()==dict[i].size()){
                    ans=min(ans,dict[i]);
                }
            }
        }
        return ans;
    }
};