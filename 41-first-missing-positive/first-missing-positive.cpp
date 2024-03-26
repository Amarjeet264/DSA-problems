class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()&&nums[i]<=0){
            i++;
        }
        int x=1;
        while(i<nums.size()){
            if(x<nums[i]){
                return x;
            }
            else{
                if(i==0||nums[i]!=nums[i-1]){
                    x++;
                }
            }
            i++;
        }
        return x;
    }
};