class Solution {
    void jodo(string &s){
        int i=s.length()-1;
        while(i>=0&&s[i]=='1'){
            s[i]='0';
            i--;
        }
        if(i>0)s[i]='1';
        else{
            s+='1';
            reverse(s.begin(),s.end());
        }
    }
public:
    int numSteps(string s) {
        int n=s.length();
        int i=n-1;
        int cnt=0;
        while(s.length()>1){
            if(s[s.size()-1]=='0'){
                s.pop_back();
            }
            else{
                jodo(s);
            }
            cnt++;
        }
        return cnt;
    }
};