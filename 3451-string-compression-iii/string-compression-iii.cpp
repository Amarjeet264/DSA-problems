class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int cnt=1;
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1]&&cnt<9){
                cnt++;
            }
            else{
                char ch=(cnt+'0');
                ans+=ch;
                ans+=word[i-1];
                cnt=1;
            }
        }
        char ch=(cnt+'0');
        ans+=ch;
        ans+=word[word.size()-1];
        return ans;
    }
};