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
        int n=s.length();
        vector<int>dp(n,0);
        if(s[0]=='0')return 0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='0'&&s[i-1]=='0'){
                dp[i]=0;
            }
            else if(s[i-1]=='0'&&s[i]!='0'){
                if(i>1)dp[i]=dp[i-1];
            }
            else if(s[i-1]!='0'&&s[i]=='0'){
                    if(s[i-1]=='1'||s[i-1]=='2'){
                        if(i>=2){
                            dp[i]=dp[i-2];
                        }
                        else{
                            dp[i]=1;
                        }
                    }
            }
            else{
                string x="";
                x+=s[i-1];
                x+=s[i];
                if(stoi(x)<=26){
                    if(i-2>=0)dp[i]=dp[i-1]+dp[i-2];
                    else dp[i]=dp[i-1]+1;
                }
                else{
                    dp[i]=dp[i-1];
                }
            }
        }
        return dp[n-1];
    }
};