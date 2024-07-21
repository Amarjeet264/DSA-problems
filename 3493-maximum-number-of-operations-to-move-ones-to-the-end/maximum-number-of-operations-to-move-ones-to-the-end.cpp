class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int cnt = 0;
        int i=0;
        while(i<s.size()){
            if(s[i]=='0'){
                ans+=cnt;
                while(i<s.size()&&s[i]=='0'){
                    i++;
                }
            }
            cnt++;
            i++;
        }
        return ans;
    }
};