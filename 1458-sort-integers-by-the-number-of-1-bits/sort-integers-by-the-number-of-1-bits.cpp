class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++){
            int cnt=0;
            int x=arr[i];
            while(x>0){
                if(x%2){
                    cnt++;
                }
                x=x/2;
            }
            pq.push({cnt,arr[i]});
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};