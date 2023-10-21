class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=0;
        int i=0;
        while(i<nums.size()){
            int starti=i;
            int endi=i+nums[i];
            if(i>=nums.size()-1)return steps;
            int maxi=-1;
            steps++;
            if(endi>=nums.size()-1)return steps;
            int idx=i;
            for(int j=starti;j<=endi;j++){
                if(maxi<j+nums[j]){
                    maxi=j+nums[j];
                    idx=j;
                }
            }
            if(i==idx)break;
            i=idx;
        }
        return 0;
    }
};