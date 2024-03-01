class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int cnt=0;
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])!=mp.end()){
                cnt++;
                mp[t[i]]--;
                if(mp[t[i]]==0){
                    mp.erase(t[i]);
                }
            }
        }
        return s.length()-cnt+t.length()-cnt;
    }
};