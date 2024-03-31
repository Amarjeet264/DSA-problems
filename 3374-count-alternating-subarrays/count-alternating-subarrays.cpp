class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long cnt=0;
        int n=nums.size();
        int i=0;
        int j=0;
        while (j<n){
            if(j-1>=i&&nums[j]==nums[j-1])i=j;
            cnt+=(j-i+1);
            if(j-1>=i&&nums[j]==nums[j-1])i=j+1;
            j++;
        }
        return cnt;
    }
};