class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            if(word[i]>='A'&&word[i]<='Z'){
                if(mp.find(word[i])==mp.end()){
                    mp[word[i]]=i;
                }
            }
            else{
                mp[word[i]]=i;
            }
        }
        int cnt=0;
        for(auto it:mp){
            if(it.first>='a'&&it.first<='z'){
                char ch=toupper(it.first);
                if(mp.find(ch)!=mp.end()&&mp[ch]>it.second){
                    mp.erase(ch);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};