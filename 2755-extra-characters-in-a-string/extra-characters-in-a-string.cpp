class Solution {
    int extra(int i,string s,unordered_map<string,int>&mp,vector<int>&dp){
        if(i>=s.length())return 0;
        if(dp[i]!=-1)return dp[i];
        string curr="";
        int mini=s.size();
        for(int j=i;j<s.length();j++){
            curr+=s[j];
            int extracnt=curr.size();
            if(mp.find(curr)!=mp.end()){
                extracnt=0;
            }
            extracnt+=extra(j+1,s,mp,dp);
            mini=min(mini,extracnt);
        }
        return dp[i]=mini;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp;
        for(int i=0;i<dictionary.size();i++){
            mp[dictionary[i]]++;
        }
        vector<int>dp(s.size(),-1);
        return extra(0,s,mp,dp);
    }
};