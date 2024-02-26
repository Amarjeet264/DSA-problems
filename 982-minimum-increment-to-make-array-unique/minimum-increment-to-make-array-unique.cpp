class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                cnt++;
                nums[i]=nums[i]+1;
            }
            else if(nums[i-1]>nums[i]){
                int x=(nums[i-1]-nums[i]+1);
                cnt+=x;
                nums[i]=nums[i]+x;
            }
        }
        return cnt;
    }
};