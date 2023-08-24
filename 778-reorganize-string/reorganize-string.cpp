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
        if(pq.size()==1&&pq.top().first==1){
            return ans+pq.top().second;
        }
        if(pq.size()<=1){
            return ans;
        }
        while(pq.size()>1){
            int ff=pq.top().first;
            char fir=pq.top().second;
            pq.pop();

            int sf=pq.top().first;
            char sec=pq.top().second;
            pq.pop();
            if(ff-1>0){
                pq.push({ff-1,fir});
            }
            ans+=fir;
            ans+=sec;
            if(sf-1>0){
                pq.push({sf-1,sec});
            }
        }
        if(!pq.empty()&&ans[ans.size()-1]==pq.top().second){
            return "";
        }
        if(!pq.empty()&&pq.top().first>1){
            return "";
        }
        if(!pq.empty()&&ans[ans.size()-1]!=pq.top().second){
            // return "";
           ans+=pq.top().second;
        }
        return ans;
    }
};