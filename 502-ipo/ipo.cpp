
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vec;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        priority_queue<int>pq;
        int idx=0;
        int sum=w;
        while(k>0){
            while(idx<profits.size()&&sum>=vec[idx].first){
                pq.push(vec[idx].second);
                idx++;
            }
            if(pq.empty())break;
            sum+=pq.top();
            pq.pop();
            k--;
        }
        return sum;
    }
};