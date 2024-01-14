class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n!=m)return false;
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[word1[i]]++;
        }
        unordered_map<int,int>mp1;
        for(int i=0;i<n;i++){
            if(mp.find(word2[i])==mp.end()){
                return false;
            }
            mp1[word2[i]]++;
        }
        // for(int i=0;i<n;i++){
        //     if(mp1.find(word1[i])==mp1.end()){
        //         return false;
        //     }
        // }
        unordered_map<int,vector<char>>cnt;
        unordered_map<int,vector<char>>cnt1;
        for(auto it:mp){
            cnt[it.second].push_back(it.first);
        }
        for(auto it:mp1){
            cnt1[it.second].push_back(it.first);
        }
        for(auto it:cnt1){
            if(cnt[it.first].size()!=it.second.size()){
                return false;
            }
        }
        return true;
    }
};