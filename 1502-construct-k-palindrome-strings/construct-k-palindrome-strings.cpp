class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto &it:mp){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second%2){
                k-=1;
                mp[it.first]--;
                if(mp[it.first]==0){
                    mp.erase(it.first);
                }
            }
        }
        if(k<0){
            return false;
        }
        int cnt=0;
        for(auto it:mp){
            cnt+=it.second;
        }
        if(cnt<k)return 0;
        return 1;
    }
};