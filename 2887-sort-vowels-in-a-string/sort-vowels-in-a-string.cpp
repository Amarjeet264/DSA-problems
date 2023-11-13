class Solution {
public:
    string sortVowels(string s) {
        string vo="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='A'||s[i]=='O'||s[i]=='E'||s[i]=='I'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                vo+=s[i];
            }
        }
        sort(vo.begin(),vo.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A'||s[i]=='O'||s[i]=='E'||s[i]=='I'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                s[i]=vo[j];
                j++;
            }
        }
        return s;
    }
};