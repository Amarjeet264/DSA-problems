class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++){
            if(!pq.empty()&&intervals[i][0]<=pq.top()){
                pq.push({intervals[i][1]});
            }
            else{
                int cnt = 0;
                if(!pq.empty()&&intervals[i][0]>pq.top()){
                    pq.pop();
                    cnt++;
                }
                cout<<cnt<<endl;
                pq.push({intervals[i][1]});
            }
        }
        return pq.size();
    }
};