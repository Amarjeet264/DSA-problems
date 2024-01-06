class Solution {
public:
    string minWindow(string a, string b) {
        if(b.length()>a.length()){
            return "";
        }
        unordered_map<char,int>mp;
        for(int i=0;i<b.size();i++){
            mp[b[i]]++;
        }
        int i=0;
        int j=0;
        int start=-1;
        int minlen=INT_MAX;
        int cnt=mp.size();
        while(j<a.size()){
            mp[a[j]]--;
            if(mp[a[j]]==0){
                cnt--;
            }
            if(cnt==0){
                while(i<=j&&mp[a[i]]<0&&cnt==0){
                    mp[a[i]]++;
                    if(mp[a[i]]==1){
                        cnt++;
                    }
                    i++;
                }
                if(minlen>j-i+1){
                    minlen=j-i+1;
                    start=i;
                }
            }
            j++;
        }
        if(start==-1){
            return "";
        }
        return a.substr(start,minlen);
    }
};