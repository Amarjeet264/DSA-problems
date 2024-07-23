class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string t="11";
        for(int i=3;i<=n;i++){
            int cnt=1;
            string s="";
            // t+='#';
            for(int j=1;j<t.length();j++){
                if(t[j]==t[j-1]){
                    cnt++;
                }
                else{
                    s+=to_string(cnt);
                    s+=t[j-1];
                    cnt=1;
                }
            }
            s+=to_string(cnt);
            s+=t[t.size()-1];
            t=s;
        }
        return t;
    }
};