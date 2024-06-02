class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>>pq;
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                int x=pq.top().second;
                x=-x;
                s[x]='#';
                mp[x]++;
                pq.pop();
            }
            else{
                pq.push({s[i],-i});
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(mp.find(i)==mp.end()&&s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};