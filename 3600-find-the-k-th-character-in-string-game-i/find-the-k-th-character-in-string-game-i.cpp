class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size()<k){
            string temp = "";
            for(int i=0;i<word.size();i++){
                if(word[i]=='z'){
                    temp+='a';
                }
                else{
                    temp += word[i]+1;
                }
            }
            word+=temp;
            // cout<<word<<endl;
        }
        return word[k-1];
    }
};