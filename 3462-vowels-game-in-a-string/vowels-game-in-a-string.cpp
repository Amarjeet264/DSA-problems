class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                cnt++;
            }
        }
        return cnt!=0;
    }
};