class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int>ans(nums.size());
        int bal=-1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=bal;
            bal=max(bal,nums[i]);
        }
        long long maxi=INT_MIN;
        long long res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(maxi>nums[i]){
                res=max(res,((long long)maxi-(long long)nums[i])*(long long)ans[i]);
            }
            maxi=max(maxi,(long long)nums[i]);
        }
        if(res<0)return 0;
        return res;
    }
};