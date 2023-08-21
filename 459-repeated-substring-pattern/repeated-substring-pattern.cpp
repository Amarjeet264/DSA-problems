class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
       for(int i=1;i<=s.length()/2;i++){
           if(n%i==0){
                string str="";
                for(int j=0;j<s.length()/i;j++){
                    str+=s[j];
                    string dup=str;
                    
                    if(str==s||str.length()>(s.length()/2)+1){
                        break;
                    }
                    while(str.length()<s.length()){
                        str+=dup;
                    }
                    if(str==s){
                        return true;
                    }
                    str=dup;
                }
           }
       }
       return false;
    }
};