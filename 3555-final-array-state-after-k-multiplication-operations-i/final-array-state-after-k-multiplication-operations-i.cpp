class Solution {
    static bool comp(pair<int,int> a, pair<int,int> b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&comp)> pq(comp);
        for(int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        while(k>0) {
            int ele = pq.top().first;
            int idx = pq.top().second;
            cout<<ele<<endl;
            pq.pop();
            pq.push({ele * multi, idx});
            k--;
        }
        vector<int> ans(nums.size());
        while(!pq.empty()) {
            int ele = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            ans[idx] = ele;
        }
        return ans;
    }
};
