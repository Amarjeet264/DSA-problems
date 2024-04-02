class Solution {
public:
    bool isIsomorphic(string str1, string str2) {
        if(str1.length()!=str2.length()){
            return 0;
        }
        map<char,char>mp;
        map<char,char>mp1;
        for(int i=0;i<str1.length();i++){
            if(mp.find(str1[i])!=mp.end()||mp1.find(str2[i])!=mp1.end()){
                if(mp[str1[i]]!=str2[i]||mp1[str2[i]]!=str1[i])
                   return false;
            }
            mp[str1[i]]=str2[i];
            mp1[str2[i]]=str1[i];
        }
        return true;
    }
};