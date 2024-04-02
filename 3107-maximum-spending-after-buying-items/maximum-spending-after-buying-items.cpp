class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=values.size();
        int m=values[0].size();
        for(int i=0;i<n;i++){
            pq.push({-values[i][m-1],{i,m-1}});
        }
        long long ans=0;
        long long day=1;
        while(!pq.empty()){
            int v=-pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            ans=ans+((long long)v*day);
            day++;
            if(col-1>=0){
                pq.push({-values[row][col-1],{row,col-1}});
            }
        }
        return ans;
    }
};