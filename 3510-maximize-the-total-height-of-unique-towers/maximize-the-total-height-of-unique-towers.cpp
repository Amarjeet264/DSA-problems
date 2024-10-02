class Solution {
public:
    long long maximumTotalSum(vector<int>&hh) {
        long long ans= 0;
        priority_queue<int>pq;
        for(int i=0;i<hh.size();i++){
            pq.push(hh[i]);
        }
        int prev = pq.top();
        pq.pop();
        ans+=prev;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(x>=prev){
                ans+=(prev-1);
                x = prev-1;
            }
            else{
                ans+=x;
            }
            if(x<=0)return -1;
            prev = x;
        }
        return ans;
    }
};