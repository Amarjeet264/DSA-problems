class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int>mp;
        int n=nums.size();
        int sum=0;
        int cnt=0;
        unordered_set<int>mp1;
        mp1.insert(0);
        mp.insert(0);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-target)!=mp.end()){
                cnt++;
                mp=mp1;
                sum=0;
                continue;
            }
            mp.insert(sum);
        }
        return cnt;
    }
};