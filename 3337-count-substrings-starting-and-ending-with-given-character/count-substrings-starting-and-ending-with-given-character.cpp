class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt=0;
        unordered_map<char,int>mp;
        for(auto it:s){
            if(it==c){
                mp[c]++;
                cnt=cnt+mp[c];
            }
        }
        return cnt;
    }
};