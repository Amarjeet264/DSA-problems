class Solution {
    bool isposs(int before,vector<int>&nums,vector<int>&change){
        int n = nums.size();
        vector<int>vec(n+1,-1);
        for(int i = 0;i<before;i++){
            vec[change[i]] = i+1;
        }
        for(int i=1;i<=n;i++){
            if(vec[i]==-1){
                return 0;
            }
        }
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            mp[vec[i]] = i;
        }
        int timePassed = 0;
        for(auto it:mp){
            int requiredTime = nums[it.second-1]+1;
            if(requiredTime+timePassed>it.first){
                return 0;
            }
            timePassed+=requiredTime;
        }
        return true;
    }
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& change) {
        int low = 1;
        int high = change.size();
        int ans = -1;
        // isposs(8,nums,change);
        while(low<=high){
            int mid = (low+high)/2;
            if(isposs(mid,nums,change)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};