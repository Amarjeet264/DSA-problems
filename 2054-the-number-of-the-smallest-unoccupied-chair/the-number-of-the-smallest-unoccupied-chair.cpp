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
            cout<<ti[idx][0]<<" "<<ti[idx][1]<<" "<<ti[idx][2]<<endl;
            int i = ti[idx][2];
            while(!pq.empty()&&ti[idx][0]>=-1*pq.top().first){
                emp.push(-pq.top().second);
                pq.pop();
            }
            if(emp.empty()){
                chair++;
                mp[i] = chair;
                pq.push({-ti[idx][1],chair});
            }
            else{
                mp[i] = -emp.top();
                pq.push({-ti[idx][1],-emp.top()});
                emp.pop();
            }
        }
        return mp[targetFriend] ;
    }
};