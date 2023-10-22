class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt0=0;
        int cntc=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt0++;
            }
            else{
                cntc++;
            }
            if(cntc>cnt0){
                ans++;
                cntc=0;
                cnt0=0;
            }
        }
        return ans+abs(cnt0-cntc);

    }
};