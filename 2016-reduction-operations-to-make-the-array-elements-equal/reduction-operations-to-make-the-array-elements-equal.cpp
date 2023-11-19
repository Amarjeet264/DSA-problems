class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            q.push({it.first,it.second});
        }
        int cnt=0;
        while(q.size()!=1){
            int first=q.top().first;
            int firstfre=q.top().second;
            q.pop();
            int second=q.top().first;
            int secondfre=q.top().second;
            q.pop();
            cnt+=firstfre;
            q.push({second,secondfre+firstfre});
        }
        return cnt;
    }
};