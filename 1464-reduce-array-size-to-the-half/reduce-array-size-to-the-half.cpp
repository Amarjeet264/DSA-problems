class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int n=arr.size();
        int size=n;
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int cnt=0;
        while(size>n/2){
            size-=pq.top().first;
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};