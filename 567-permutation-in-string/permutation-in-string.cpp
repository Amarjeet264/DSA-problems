class Solution {
public:
    bool checkInclusion(string p, string s) {
        vector<int>freq(26,0);
        vector<int>wind(26,0);
        if(s.size() < p.size()) return {};
        for(int i=0;i<p.length();i++){
            freq[p[i]-'a']++;
        }
        for(int i=0;i<p.length();i++){
            wind[s[i]-'a']++;
        }
        int j=p.length();
        if(freq==wind){
            return true;
        }
        int i=0;
        while(j<s.length()){
            wind[s[i]-'a']--;
            wind[s[j]-'a']++;
            if(wind==freq){
                return true;
            }
            j++;
            i++;
        }
        return false;
    }
};