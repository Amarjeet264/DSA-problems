class Solution {
    unordered_map<string,int>mp;
    vector<vector<string>>ans;
    string beg;
    void dfs(string word,vector<string>&dup){
        if(word==beg){
            reverse(dup.begin(),dup.end());
            ans.push_back(dup);
            reverse(dup.begin(),dup.end());
            return;
        }
        int steps=mp[word];
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mp.find(word)!=mp.end()&&mp[word]==steps-1){
                    dup.push_back(word);
                    dfs(word,dup);
                    dup.pop_back();
                }
            }
            word[i]=original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        mp[beginWord]=1;
        beg=beginWord;
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front();
            int steps=mp[word];
            q.pop();
            if(endWord==word){
                break;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }
        if(mp.find(endWord)!=mp.end()){
            vector<string>dup;
            dup.push_back(endWord);
            dfs(endWord,dup);
        }
        return ans;

    }
};