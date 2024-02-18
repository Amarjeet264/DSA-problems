class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m=meetings.size();
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        priority_queue<int,vector<int>,greater<int>>free;
        for(int i=0;i<n;i++){
            free.push(i);
        }
        vector<int>mp(n,0);
        for(int i=0;i<m;i++){
            if(!pq.empty()){
                while(!pq.empty()&&pq.top().first<=meetings[i][0]){
                    free.push(pq.top().second);
                    pq.pop();
                }
                if(!free.empty()){
                    pq.push({meetings[i][1],free.top()});
                    mp[free.top()]++;
                    free.pop();
                }
                else{
                    long long kmend=pq.top().first;
                    int room=pq.top().second;
                    pq.pop();
                    long long x=kmend-meetings[i][0];
                    pq.push({meetings[i][1]+x,room});
                    mp[room]++;
                }
            }
            else{
                pq.push({meetings[i][1],free.top()});
                mp[free.top()]++;
                free.pop();
            }
        }
        int maxi=0;
        int roomno=101;
        for(int i=0;i<n;i++){
            if(mp[i]>maxi){
                maxi=mp[i];
                roomno=i;
            }
        }
        return roomno;
    }
};