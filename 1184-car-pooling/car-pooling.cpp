class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       sort(trips.begin(),trips.end(),comp);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       for(int i=0;i<trips.size();i++){
           while(!pq.empty()&&trips[i][1]>=pq.top().first){
               capacity+=pq.top().second;
               pq.pop();
           }
           if(capacity>=trips[i][0]){
               pq.push({trips[i][2],trips[i][0]});
               capacity-=trips[i][0];
           }
           else{
               return false;
           }
       }
       return true;
    }
};