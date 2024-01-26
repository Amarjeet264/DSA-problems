class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int i=0;
        int j=0;
        int cnt=0;
        sort(nums.begin(),nums.end());
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else{
                cnt++;
                i++;
                j++;
            }
        }
        return cnt;
    }
};