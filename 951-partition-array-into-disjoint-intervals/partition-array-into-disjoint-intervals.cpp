class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // map<int,int>left;
        // map<int,int>mp;
        vector<int>left;
        vector<int>vec;
        int maxi1=0;
        int maxi=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(left.size()==0){
                // left[nums[i]]++;
                left.push_back(nums[i]);
                maxi1=nums[i];
            }
            else {
                // auto last = left.rbegin();
                if(maxi1>nums[i]){
                    left=vec;
                    // left[nums[i]]++;
                    left.push_back(nums[i]);
                    maxi1=maxi;
                }
            }
            maxi=max(maxi,nums[i]);
            vec.push_back(nums[i]);
            // mp[nums[i]]++;
        }
        // for(auto it:left){
        //     ans+=it.second;
        // }
        return left.size();
    }
};