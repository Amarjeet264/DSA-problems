class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.length()-1;
        int len=s.length();
        while(i<j){
            char ch1=s[i];
            char ch2=s[j];
            if(s[i]!=s[j]){
                break;
            }
            while(i<=j&&s[i]==ch2){
                i++;
                len--;
            }
            while(j>=i&&s[j]==ch1){
                j--;
                len--;
            }
        }
        return len;
    }
};