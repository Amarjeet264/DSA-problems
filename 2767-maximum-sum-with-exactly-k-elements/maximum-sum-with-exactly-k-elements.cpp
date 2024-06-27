class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        if(k==0)return 0;
        sort(nums.begin(),nums.end());
        int sum=nums[nums.size()-1];
        int ele=sum+1;
        k-=1;
        while(k--){
            sum+=ele;
            ele=ele+1;
        }
        return sum;
    }
};