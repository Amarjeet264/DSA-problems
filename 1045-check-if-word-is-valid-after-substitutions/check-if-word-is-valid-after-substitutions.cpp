class Solution {
public:
    bool isValid(string s) {
        int i=0;
        int j=0;
        string t="abc";
        while(t.length()<s.length()){
            if(t[i]==s[j]){
                i++;
                j++;
                if(i==t.length()&&j<s.length()){
                    if(s[j]=='a')t+="abc";
                    else return 0;
                }
                else if(i==s.length()&&j==t.length()){
                    return true;
                }
            }
            else{
                if(s[j]!='a'){
                    return false;
                }
                string x=t.substr(0,i);
                string y=t.substr(i,t.length());
                string nayi="";
                nayi+=x;
                nayi+="abc";
                nayi+=y;
                t=nayi;
                j++;
                i++;
            }
        }
        if(t.length()==s.length()){
            for(int i=0;i<t.length();i++){
                if(s[i]!=t[i])return 0;
            }
        }
        else return false;
        return true;
    }
};