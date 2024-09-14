class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        int start = -1;
        int end = -1;
        int maxi = 0;
        for(int i=0;i<n;i++){
            vector<int>sma(26);
            vector<int>big(26);
            for(int j = i;j<n;j++){
                if(s[j]>='a'&&s[j]<='z'){
                    sma[s[j]-'a']=1;
                }
                else{
                    big[s[j]-'A']=1;
                }
                bool ha = 1;
                for(int k = 0;k<26;k++){
                    if(sma[k]!=big[k]){
                        ha = 0;
                    }
                }
                if(ha){
                    if(maxi<j-i+1){
                        maxi = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        if(start==-1)return "";
        return s.substr(start,maxi);
    }
};