class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<vector<int>>ti;
        for(int i = 0;i<times.size();i++){
            ti.push_back({times[i][0],times[i][1],i});
        }
        sort(ti.begin(),ti.end());
        priority_queue<pair<int,int>>pq;
        priority_queue<int>emp;
        emp.push(0);
        int chair = 0;
        unordered_map<int,int>mp;
        for(int idx =0;idx<ti.size();idx++){
            int i = ti[idx][2];
            while(!pq.empty()&&ti[idx][0]>=-1*pq.top().first){
                emp.push(-pq.top().second);
                pq.pop();
            }
            int ans = -1;
            if(emp.empty()){
                chair++;
                ans = chair;
                pq.push({-ti[idx][1],chair});
            }
            else{
                ans = -emp.top();
                pq.push({-ti[idx][1],-emp.top()});
                emp.pop();
            }
            if(targetFriend==i){
                return ans;
            }
        }
        return mp[targetFriend] ;
    }
};