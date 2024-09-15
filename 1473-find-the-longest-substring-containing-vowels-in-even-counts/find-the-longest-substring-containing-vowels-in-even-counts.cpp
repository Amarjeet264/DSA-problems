class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<vector<bool>,int>mp;
        int ans = 0;
        int a=0;
        int e=0;
        int x=0;
        int o=0;
        int u=0;
        mp[{0,0,0,0,0}] = -1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                a++;
            }
            else if(s[i]=='e'){
                e++;
            }
            else if(s[i]=='i'){
                x++;
            }
            else if(s[i]=='o'){
                o++;
            }
            else if(s[i]=='u'){
                u++;
            }
            vector<bool>temp;
            temp.push_back(a%2);
            temp.push_back(e%2);
            temp.push_back(x%2);
            temp.push_back(o%2);
            temp.push_back(u%2);
            if(mp.find(temp)!=mp.end()){
                ans=max(ans,i-mp[temp]);
            }
            else{
                mp[temp]=i;
            }
        }
        return ans;
    }
};