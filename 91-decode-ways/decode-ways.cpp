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
        vector<int>dp(s.length()+1,-1);
        // int i=1;
        // while(i<=s.length()){
        //     int one=0;
        //     int two=0;
        //     if(s[i-1]!='0'){
        //         one=dp[i-1];
        //         i++;
        //     }
        //     string x="";
        //     if(s[i-1]!='0'&&i<=s.length()){
        //             x+=s[i-1];
        //             x+=s[i];
        //             if((stoi(x))<=26){
        //                 two=dp[i+2];
        //             }
        //             i+=2;
        //     }
        //      return dp[i]= one+two;
        // }
        return decode(0,s,dp);
    }
};