class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int val=0;
        if(n%2==0){
            val=nums[n/2]+nums[(n/2)-1];
            val/=2;
        }
        else{
            val=nums[n/2];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=abs(nums[i]-val);
        }
        return cnt;
    }
};