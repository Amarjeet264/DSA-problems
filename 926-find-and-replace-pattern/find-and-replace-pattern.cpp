class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string str2) {
        vector<string>ans;
        for(int i=0;i<words.size();i++){
            string str1=words[i];
            if(str1.size()!=str2.size())continue;
            map<char,char>mp;
            map<char,char>mp1;
            bool flag=1;
            for(int i=0;i<str1.length();i++){
                if(mp.find(str1[i])!=mp.end()||mp1.find(str2[i])!=mp1.end()){
                    if(mp[str1[i]]!=str2[i]||mp1[str2[i]]!=str1[i]){
                        flag=false;
                    }
                }
                mp[str1[i]]=str2[i];
                mp1[str2[i]]=str1[i];
            }
            if(flag){
                ans.push_back(str1);
            }
        }
        return ans;
    }
};