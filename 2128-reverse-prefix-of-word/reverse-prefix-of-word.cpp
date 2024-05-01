class Solution {
public:
    string reversePrefix(string word, char ch) {
        string x="";
        int i=0;
        while(i<word.size()){
            x+=word[i];
            if(word[i]==ch){
                break;
            }
            i++;
        }
        if(i==word.size()){
            return word;
        }
        reverse(x.begin(),x.end());
        i++;
        while(i<word.size()){
            x+=word[i];
            i++;
        }
        return x;
    }
};