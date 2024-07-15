class Solution {
public:
    int partitionString(string s) {
        vector<int>pre(26,-1);
        
        int cnt=1;
        int start = 0;
        for(int i=0;i<s.length();i++){
            if(pre[s[i]-'a']>=start){
                cnt++;
                start = i;
            }
            pre[s[i]-'a'] = i;
        }
        return cnt;
    }
};