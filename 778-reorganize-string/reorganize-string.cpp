class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(pq.size()>0){
            int ff=pq.top().first;
            char fir=pq.top().second;
            pq.pop();
            ans+=fir;
            if(pq.empty()){
                continue;
            }
            int sf=pq.top().first;
            char sec=pq.top().second;
            pq.pop();
            if(ff-1>0){
                pq.push({ff-1,fir});
            }
            ans+=sec;
            if(sf-1>0){
                pq.push({sf-1,sec});
            }
        }
        if(ans.size()!=s.size()){
            return "";
        }
        return ans;
    }
};