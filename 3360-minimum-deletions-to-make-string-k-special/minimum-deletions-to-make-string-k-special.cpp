class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        vector<int>fre;
        for(auto it:mp){
            fre.push_back(it.second);
        }
        sort(fre.begin(),fre.end());
        int mx=fre.back();
        int ans=1e9;
        for(int i=1;i<=mx;i++){
            int cnt=0;
            for(int j=0;j<fre.size();j++){
                if(fre[j]>i+k){
                    cnt+=fre[j]-i-k;
                }
                else if(fre[j]<i){
                    cnt+=fre[j];
                }
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};