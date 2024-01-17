class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int k=mp.size();
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>mp1;
            for(int j=i;j<nums.size();j++){
                mp1[nums[j]]++;
                if(mp1.size()==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};