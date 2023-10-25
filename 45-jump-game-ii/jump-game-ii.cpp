class Solution {
public:
    int jump(vector<int>& nums) { 
        if(nums.size()<=1)return 0;
        int j=0;
        int steps=1;
        while(j<nums.size()){
            int start=j;
            int maxi=j+nums[j];
            if(maxi>=nums.size()-1){
                return steps;
            }
            steps++;
            int idx=j;
            for(int i=start+1;i<=start+nums[j];i++){
                if(maxi<i+nums[i]){
                    maxi=max(maxi,i+nums[i]);
                    idx=i;
                }
            }
            if(idx==j){
                return -1;
            }
            j=idx;
        }
        return -1;
    }
};