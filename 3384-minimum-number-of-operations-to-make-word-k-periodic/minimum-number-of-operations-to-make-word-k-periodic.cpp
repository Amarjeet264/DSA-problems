class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<word.size();i+=k){
            string s=word.substr(i,k);
            // cout<<s<<" ";
            // cout<<i<<" ";
            mp[s]++;
        }
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        int z=k*maxi;
        int bacha=word.size()-z;
        return (bacha/(k));
        // 1800116677  acersupport@in.aegisglobal.com
    }
};