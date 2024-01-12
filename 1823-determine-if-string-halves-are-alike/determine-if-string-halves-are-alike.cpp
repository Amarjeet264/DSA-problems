class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        int cnt=0;
        for(int i=0;i<n/2;i++){
            if(s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u'||s[i]=='A'||s[i]=='O'||s[i]=='E'||s[i]=='I'||s[i]=='U'){
                cnt++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(s[i]=='a'||s[i]=='o'||s[i]=='e'||s[i]=='i'||s[i]=='u'||s[i]=='A'||s[i]=='O'||s[i]=='E'||s[i]=='I'||s[i]=='U'){
                cnt--;
            }
        }
        return cnt==0;
    }
};