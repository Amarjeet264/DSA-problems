class Solution {
public:
    int minTimeToType(string word) {
        int time=0;
        char ch='a';
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                time++;
                continue;
            }
            else{
                time++;
                if(abs(ch-word[i])<=13){
                    time+=abs(ch-word[i]);
                }
                else{
                    int x=abs(ch-word[i]);
                    time+=26-x;
                }
                ch=word[i];
            }
        }
        return time;
    }
};