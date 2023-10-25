class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;
        }
        int j=0;
        int start=-1;
        int minlen=INT_MAX;
        int i=0;
        int cnt=0;
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    cnt++;
                }
            }
            if(mp.size()==cnt){
                while(i<=j&&mp.size()==cnt){
                    if(minlen>j-i+1){
                        minlen=j-i+1;
                        start=i;
                    }
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]>0)cnt--;
                    }
                    i++;
                }
            }
            j++;
        }
        if(minlen==INT_MAX)return "";
        return s.substr(start,minlen);
    }
};