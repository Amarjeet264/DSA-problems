class Solution {
        unordered_map<char,int>mp;
        unordered_map<string,int>mp1;
        int total=0;

        int calc(vector<string>&words,vector<int>&score,int i){
            if(i>=words.size()){
                return 0;
            }
            if(mp1.find(words[i])==mp1.end()){
                return calc(words,score,i+1);
            }

            bool can=true;
            int amount=0;
            int take=0;
            int kahatk=-1;
            for(int j=0;j<words[i].size();j++){
                if(mp.find(words[i][j])==mp.end()){
                    kahatk=j-1;
                    can=false;
                    break;
                }
                mp[words[i][j]]--;
                if(mp[words[i][j]]==0)mp.erase(words[i][j]);
                amount+=score[words[i][j]-'a'];
            }
            if(can){
                mp1[words[i]]--;
                if(mp1[words[i]]==0){
                    mp1.erase(words[i]);
                }
                take=amount+calc(words,score,i+1);
                mp1[words[i]]++;
                for(int j=0;j<words[i].size();j++){
                    mp[words[i][j]]++;
                }
            }
            else{
                for(int j=0;j<=kahatk;j++){
                    mp[words[i][j]]++;
                }
            }
            int nottake=calc(words,score,i+1);
            return max(take,nottake);
        }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(int i=0;i<letters.size();i++){
            mp[letters[i]]++;
        }
        for(int i=0;i<words.size();i++){
            mp1[words[i]]++;
        }
        return calc(words,score,0);
    }
};