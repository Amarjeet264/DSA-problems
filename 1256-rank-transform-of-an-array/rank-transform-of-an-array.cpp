class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        sort(arr.begin(),arr.end());
        int cnt = 2;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=arr[i-1]){
                cnt++;
            }
        }
        int prev = -1;
        while(!pq.empty()){
            if(prev!=pq.top().first){
                cnt--;
            }
            arr[pq.top().second] = cnt;
            prev = pq.top().first;
            pq.pop();
        }
        return arr;
    }
};