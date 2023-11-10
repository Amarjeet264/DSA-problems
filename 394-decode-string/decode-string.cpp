class Solution {
    string solve(string s,int &i){
        string ans;
        while(i<s.length()&&s[i]!=']'){
            if(isdigit(s[i])){
                int k=0;
                while(i<s.length()&&isdigit(s[i])){
                    k=k*10+(s[i]-'0');
                    i++;
                }
                i++;//[
                string temp=solve(s,i);
                i++;//]
                while(k--){
                    ans+=temp;
                }
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
public:
    string decodeString(string s) {
        int i=0;
        return solve(s,i);
    }
};