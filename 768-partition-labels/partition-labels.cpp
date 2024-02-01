class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        int i=0;
        while(i<s.length()){
            int maxi=mp[s[i]];
            string str="";
            while(i<=maxi){
                str+=s[i];
                maxi=max(maxi,mp[s[i]]);
                i++;
            }
            ans.push_back(str.size());
        }
        return ans;
    }
};