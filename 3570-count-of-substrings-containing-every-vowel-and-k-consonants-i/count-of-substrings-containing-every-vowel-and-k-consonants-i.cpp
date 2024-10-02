class Solution {
    bool isVow(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            return 1;
        }
        return 0;
    }
public:
    int countOfSubstrings(string word, int k) {
        int res = 0;
        for(int i = 0;i<word.size();i++){
            int cnt = 0;
            unordered_map<char,int>mp;
            for(int j=i;j<word.size();j++){
                if(isVow(word[j])){
                    mp[word[j]]++;
                }
                else{
                    cnt++;
                }
                if(cnt==k&&mp.size()==5){
                    res++;
                }
            }
        }
        return res;
    }
};