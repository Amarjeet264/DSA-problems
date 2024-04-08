class Solution {
public:
    string getSmallestString(string s, int k) {
        string t="";
        for(int i=0;i<s.length();i++){
            for(char ch='a';ch<='z';ch++){
                int dis=min(s[i]-ch,('z'-s[i])+(ch-'a')+1);
                // cout<<dis<<endl;
                if(dis<=k){
                    t+=ch;
                    k-=dis;
                    break;
                }
                else if(ch>=s[i]){
                    t+=s[i];
                    break;
                }
            }
        }
        return t;
    }
};