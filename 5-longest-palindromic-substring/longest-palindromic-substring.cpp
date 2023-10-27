class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0)return "";
        int j=0;
        int maxi=1;
        int start=0;
        while(j<s.length()){
            int left=j-1;
            int right=j+1;
            while(left>=0&&right<s.length()&&s[left]==s[right]){
                if(maxi<right-left+1){
                    maxi=max(maxi,right-left+1);
                    start=left;
                }
                left--;
                right++;
            }
            left=j;
            right=j+1;
            while(left>=0&&right<s.length()&&s[left]==s[right]){
                if(maxi<right-left+1){
                    maxi=max(maxi,right-left+1);
                    start=left;
                }
                left--;
                right++;
            }
            j++;
        }
        return s.substr(start,maxi);
    }
};