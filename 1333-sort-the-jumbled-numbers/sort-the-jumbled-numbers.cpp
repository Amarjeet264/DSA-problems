class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0;i<nums.size(); i++){
            string s = to_string(nums[i]);
            int x = 0;
            for(int j = 0;j<s.size();j++){
                int mapValue = mapping[s[j]-'0'];
                x = x*10 + mapValue;
            }
            pq.push({x,i});
        }
        vector<int>ans;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};