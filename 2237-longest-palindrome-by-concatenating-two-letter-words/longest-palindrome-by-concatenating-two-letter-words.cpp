class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        int cnt=0;
        bool same=0;
        for(int i=0;i<words.size();i++){
            string x=words[i];
            if(mp.find(x)==mp.end()){
                continue;
            }
            string y=x;
            reverse(y.begin(),y.end());
            if(x==y){
                if(mp[x]>=2){
                    cnt+=4;
                    mp[x]-=2;
                    if(mp[x]<=0){
                        mp.erase(x);
                    }
                }
                else{
                    same=1;
                }
            }
            else if(mp.find(y)!=mp.end()){
                cout<<i<<" "<<x<<" "<<y<<endl;
                cnt+=4;
                mp[x]--;
                mp[y]--;
                cout<<mp[x]<<" "<<mp[y]<<endl;
                if(mp[x]<=0){
                    mp.erase(x);
                }
                if(mp[y]<=0){
                    mp.erase(y);
                }
            }
        }
        if(same)cnt+=2;
        return cnt;
    }
};