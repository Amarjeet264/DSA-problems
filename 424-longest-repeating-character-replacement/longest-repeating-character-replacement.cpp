class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int maxi=0;
        int ch[26]={0};
        while(j<s.length()){
            ch[s[j]-'A']++;
            while(j-i-*max_element(ch,ch+26)>=k){
                ch[s[i]-'A']--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};