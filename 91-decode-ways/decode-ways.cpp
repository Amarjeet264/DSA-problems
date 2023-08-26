class Solution {
    int decode(int i,string s,vector<int>&dp){
        if(i>=s.length()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=0;
        if(s[i]!='0')one=decode(i+1,s,dp);
        string x="";
        int two=0;
        if(s[i]!='0'&&i+1<s.length()){
            x+=s[i];
            x+=s[i+1];
            if((stoi(x))<=26){
                two=decode(i+2,s,dp);
            }
        }
        return dp[i]= one+two;
    }
public:
    int numDecodings(string s) {
        int a = 1, b = s[0] != '0';
        for(int i = 1; i < s.size(); ++i) {
            int c = s[i] != '0' ? b : 0;
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] - '1' + 1 < 7))
                c += a;
            a = b; b = c;
        }
        return b;
    }
};