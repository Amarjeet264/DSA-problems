struct comp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {

        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto it:words)
        {
            mp[it]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        vector<string>ans;
        for(int i=0;i<k;i++)
        if(!pq.empty()) 
        {
            auto it=pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
    }
};