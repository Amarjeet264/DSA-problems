class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        priority_queue<pair<char,int>>pq;
        vector<int>vis(26,0);
        for(int i=0;i<s.length();i++){
            vis[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(vis[s[i]-'a']>0)
            pq.push({s[i],vis[s[i]-'a']});
            vis[s[i]-'a']=0;
        }
        string ans="";
        while(!pq.empty()){
            char t=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            int freq=min(limit,x);
            x-=freq;

            while(freq>0){
                ans+=t;
                freq--;
            }
            if(pq.empty()||x==0)continue;
            char t1=pq.top().first;
            int x1=pq.top().second;
            pq.pop();
                ans+=t1;
                x1-=1;
            if(x>0){
                pq.push({t,x});
            }
            if(x1>0){
                pq.push({t1,x1});
            }
        }
        return ans;
    }
};