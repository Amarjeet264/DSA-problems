class Solution {
    unordered_map<char,int>mp;
    bool isposs(string s){
        unordered_map<char,int>mp1;
        for(int i=0;i<s.size();i++){
            if(mp1.find(s[i])!=mp1.end()||mp.find(s[i])!=mp.end()){
                return false;
            }
            mp1[s[i]]++;
        }
        return true;
    }
    int maxi(int i,vector<string>&arr){
        if(i>=arr.size()){
            return 0;
        }
        int nottake=maxi(i+1,arr);
        int take=0;
        if(isposs(arr[i])){
            for(int j=0;j<arr[i].size();j++){
                mp[arr[i][j]]++;
            }
            take=arr[i].size()+maxi(i+1,arr);
             for(int j=0;j<arr[i].size();j++){
                mp[arr[i][j]]--;
                if(mp[arr[i][j]]==0){
                    mp.erase(arr[i][j]);
                }
            }
        }
        return max(take,nottake);
    }
public:
    int maxLength(vector<string>& arr) {
        return maxi(0,arr);
    }
};