class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>allfre(26,0);
        for(auto &ch:words2[0]){
            allfre[ch-'a']++;
        }
        for(int i=1;i<words2.size();i++){
            vector<int>temp(26,0);
            for(char &ch:words2[i]){
                if(allfre[ch-'a']<1+temp[ch-'a']){
                    allfre[ch-'a']++;
                }
                temp[ch-'a']++;
            }
        }
        for(auto &str:words1){
            vector<int>fre(26,0);
            for(auto ch:str){
                fre[ch-'a']++;
            }
            bool can=1;
            for(int i=0;i<26&&can;i++){
                if(fre[i]<allfre[i]){
                    can=0;
                }
            }
            if(can){
                ans.push_back(str);
            }
        }
        return ans;
    }
};