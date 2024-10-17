class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int>pre(s.size(),-1);
        int idx = s.size()-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]-'0'>s[idx]-'0'){
                idx = i;
            }
            if(s[idx]!=s[i])pre[i] = idx;
        }
        for(int i = 0;i<s.size();i++){
            if(pre[i]!=-1){
                swap(s[i],s[pre[i]]);
                break;
            }
        }
        return stoi(s);
    }
};