class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            string ans=s;
            for(int i=1;i<s.length();i++){
                ans=min(ans,s[i]+s.substr(i+1,s.length()-i)+s.substr(0,i));
            }
            return ans;
        }
        sort(s.begin(),s.end());
        return s;
    }
};