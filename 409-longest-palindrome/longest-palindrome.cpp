class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        bool odd =0;
        int ans=0;
        for(auto it:mp){
            if(it.second%2==1){
                ans+=(it.second-1);
                odd=1;
            }
            else{
                ans+=it.second;
            }
        }
        if(odd){
            ans++;
        }
        return ans;
    }
};