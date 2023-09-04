class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        map<char, int> mpp;
        for (auto x: s)
        {
            mpp[x]++;
        }
        priority_queue<pair<char, int>> pq;
        for (auto x: mpp)
        {
            pq.push({ x.first,x.second });
        }
        string ans="";
        while(!pq.empty()){
            auto x = pq.top();
            int k = limit;
            int freq = x.second;
            char t = x.first;
            pq.pop();
            int mi = min(k, freq);
            freq -= mi;
            ans += string(mi, t);

            if(pq.empty()||freq==0)continue;
            char t1=pq.top().first;
            int freq2=pq.top().second;
            pq.pop();
            ans+=t1;
            freq2-=1;
            if(freq>0){
                pq.push({t,freq});
            }
            if(freq2>0){
                pq.push({t1,freq2});
            }
        }
        return ans;
    }
};