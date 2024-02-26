class Solution {
public:
    int minInsertions(string s) {
        int open=0;
        int close=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open>0){
                    if(i+1<s.size()&&s[i+1]==')'){
                        open--;
                        i++;
                    }
                    else{
                        cnt++;
                        open--;
                    }
                }
                else{
                    if(i+1<s.size()&&s[i+1]==')'){
                        cnt++;
                        i++;
                    }
                    else{
                        cnt+=2;
                    }
                }
            }
        }
        cnt=cnt+2*open;
        return cnt;
    }
};