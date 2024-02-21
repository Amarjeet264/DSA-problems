class Solution {
public:
    int partitionString(string s) {
        vector<int>pre(26,0);
        vector<int>dup(26,0);
        int cnt=1;
        for(int i=0;i<s.length();i++){
            if(pre[s[i]-'a']==0){
                pre[s[i]-'a']=1;
            }
            else{
                cnt++;
                pre=dup;
                pre[s[i]-'a']=1;
            }
            cout<<i<<" "<<cnt<<endl;
        }
        // cnt++;
        return cnt;
    }
};