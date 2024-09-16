class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0;i<nums.size();i++){
            int cnt = 1;
            bool neg = 0;
            int idx = i+1;
            while(idx<nums.size()){
                if(!neg&&nums[idx]-nums[idx-1]==1){
                    cnt++;
                }
                else if(neg&&nums[idx]-nums[idx-1]==-1){
                    // i = idx-1;
                    cnt++;
                }
                else{
                    // i = idx - 1;
                    idx-=2;
                    break;
                }
                neg = !neg;
                idx++;
            }
            if(i<idx){
                i = idx;
            }
            maxi = max(maxi ,cnt);
        }

        return maxi==1?-1:maxi;
    }
};