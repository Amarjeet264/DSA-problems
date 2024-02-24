class Solution {
    static bool comp(string &a,string &b){
        if(a.size()==b.size()){
            return a<b;
        }
        return a.size()<b.size();
    }
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        unordered_map<char,int>mp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                mp[words[i][j]]++;
            }
        }
        int odd=0;
        int even=0;
        for(auto it:mp){
            if(it.second%2){
                odd++;
                even=even+(it.second-1);
            }
            else{
                even+=it.second;
            }
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            if(words[i].size()%2==0){
                even-=words[i].size();
                if(even>=0)cnt++;
            }
            else{
                if(odd==0){
                    even-=2;
                    odd++;
                    if(even>=0)cnt++;
                }
                else{
                    odd--;
                    even-=(words[i].size()-1);
                    if(even>=0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};