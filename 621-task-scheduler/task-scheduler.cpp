class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        for(auto it:mp){
            pq.push(it.second);
        }
        int t=0;
        while(!pq.empty()||!q.empty()){
            int fre=0;
            if(!pq.empty()){
                fre=pq.top();
                pq.pop();
            }
            if(fre>1){
                q.push({t+n,fre-1});
            }
            if(q.front().first==t){
                pq.push(q.front().second);
                q.pop();
            }
            t++;
        }
        return t;
    }
};