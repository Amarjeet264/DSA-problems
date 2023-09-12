class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int cnt=0;
        while(!pq.empty()){
            int first=pq.top();
            pq.pop();
            if(pq.empty())break;
            int second=pq.top();
            pq.pop();

            if(first==second){
                first=first-1;
                if(first>0)pq.push(first);
                pq.push(second);
                cnt++;
            }
            
            else{
                pq.push(second);
            }
        }
        return cnt;
    }
};