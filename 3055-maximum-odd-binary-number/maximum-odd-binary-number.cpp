class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
            }
        }
        string ans="";
        while(cnt>1){
            ans+='1';
            cnt--;
        }
        while(ans.size()<s.size()-1){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};