class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int idx = -1;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp['a']>=k&&mp['b']>=k&&mp['c']>=k){
                idx = i;
                break;
            }
        }
        if(idx==-1)return -1;
        int j = n-1;
        int mini = idx+1;
        // cout<<idx<<endl;
        for(int i=idx;i>=0;i--){
            mp[s[i]]--;
            if(mp['a']>=k&&mp['b']>=k&&mp['c']>=k){
                mini = min(mini,i+(n-j)-1);
                // cout<<i<<" "<<j<<endl;
            }
            else{
                mp[s[j]]++;
                j--;
            }
        }
        return mini;
    }
};