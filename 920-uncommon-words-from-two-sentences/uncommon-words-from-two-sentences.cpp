class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp;
        string s = "";
        for(int i =0;i<s1.size();i++){
            if(s1[i]==' '){
                mp[s]++;
                s="";
            }
            else{
                s+=s1[i];
            }
        }
        if(s.size())mp[s]++;
        s = "";
        for(int i = 0;i<s2.size();i++){
            if(s2[i]==' '){
                mp[s]++;
                s="";
            }
            else{
                s+=s2[i];
            }
        }
        if(s.size())mp[s]++;
        vector<string>ans;
        for(auto it:mp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};