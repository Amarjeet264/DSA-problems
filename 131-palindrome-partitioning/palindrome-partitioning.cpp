class Solution {
    vector<vector<string>>ans;
    bool ispalin(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    void collect(string s,int i,vector<string>dup){
        if(i>=s.length()){
            ans.push_back(dup);
            return;
        }
        string x="";
        for(int j=i;j<s.length();j++){
            x+=s[j];
            if(ispalin(s,i,j)){
                dup.push_back(x);
                collect(s,j+1,dup);
                dup.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>dup;
        collect(s,0,dup);
        return ans;
    }
};