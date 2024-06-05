class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int>mp;
        for(auto it:words[0]){
            mp[it]++;
        }
        for(int i=1;i<words.size();i++){
            unordered_map<char,int>mp1;
            for(auto it:words[i]){
                mp1[it]++;
            }
            for(auto it:mp){
                int x=it.first;
                // if(mp1.find(it.first)==mp1.end()){
                //     // mp.erase(x);
                // }
                if(mp1[it.first]<mp[it.first]){
                    mp[it.first]=mp1[it.first];
                }
            }
        }
        vector<string>ans;
        for(auto it:mp){
            int x=it.second;
            while(x--){
                string s="";
                s+=it.first;
                ans.push_back(s);
            }
        }
        return ans;
    }
};