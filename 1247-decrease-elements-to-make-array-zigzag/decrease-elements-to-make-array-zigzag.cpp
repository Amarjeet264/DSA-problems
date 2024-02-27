class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int first=0;
        bool less=1;
        vector<int>dup=nums;
        for(int i=1;i<nums.size();i++){
            if(less){
                if(nums[i]>=nums[i-1]){
                    int x=nums[i]-nums[i-1]+1;
                    first+=(nums[i]-nums[i-1]+1);
                    nums[i]=nums[i]-x;
                }
            }
            else{
                if(nums[i]<=nums[i-1]){
                    first+=(nums[i-1]-nums[i]+1);
                }
            }
            less=!less;
        }
        int second=0;
        bool greater=0;
        nums=dup;
        for(int i=1;i<nums.size();i++){
            if(greater){
                if(nums[i]>=nums[i-1]){
                    int x=nums[i]-nums[i-1]+1;
                    second+=(nums[i]-nums[i-1]+1);
                    nums[i]=nums[i]-x;
                }
            }
            else{
                if(nums[i]<=nums[i-1]){
                    second+=(nums[i-1]-nums[i]+1);
                }
            }
            greater=!greater;
        }
        // cout<<first<<" "<<second<<" ";
        return min(first,second);
    }
};