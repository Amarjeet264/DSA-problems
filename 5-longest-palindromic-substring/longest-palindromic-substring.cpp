class Solution {
    
public:
    string longestPalindrome(string s) {
        int maxi=0;
        string ans="";
        int start=-1;
        for(int i=0;i<s.length();i++){
            int left=i-1;
            int right=i+1;
            while(left>=0&&right<s.length()){
                if(s[left]==s[right]){
                    if(maxi<right-left+1){
                        maxi=right-left+1;
                        start=left;
                    }
                    left--;
                    right++;
                    // cout<<left<<" "<<right<<endl;
                }
                else{
                    break;
                }
            }
            left=i;
            right=i+1;
             while(left>=0&&right<s.length()){
                if(s[left]==s[right]){
                    if(maxi<right-left+1){
                        maxi=right-left+1;
                        start=left;
                    }
                    left--;
                    right++;
                }
                else{
                    break;
                }
            }
        }
        // cout<<start<<" "<<maxi<<" ";
        if(start==-1){
            if(s.length()!=0){
                return ans+s[0];
            }
            else{
                return "";
            }
        }
        return s.substr(start,maxi);
    }
};