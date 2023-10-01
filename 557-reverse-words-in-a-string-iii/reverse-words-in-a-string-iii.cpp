class Solution {
public:
    string reverseWords(string s) {
        string h="";
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '&&h!="")
            {
                reverse(h.begin(),h.end());
                ans+=h+' ';
                h="";
                continue;
            }
            h+=s[i];
        }
        reverse(h.begin(),h.end());
        ans+=h;
        return ans;
    }
};