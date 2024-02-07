class Solution {
public:
    string frequencySort(string s) {
        int i=0;
        map<char,int>mp;
        while(i<s.length()){
            mp[s[i]]++;
            i++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            pair<int,char>p=pq.top();
            pq.pop();
            for(int i=0;i<p.first;i++){
                ans+=p.second;
            }
        }
        return ans;
    }
};