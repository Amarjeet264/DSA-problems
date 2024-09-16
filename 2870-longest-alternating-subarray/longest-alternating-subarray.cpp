class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0;i<nums.size();i++){
            int cnt = 1;
            bool neg = 0;
            int idx = i;
            for(int j=i+1;j<nums.size();j++){
                if(!neg&&nums[j]-nums[j-1]==1){
                    i = j;
                    cnt++;
                }
                else if(neg&&nums[j]-nums[j-1]==-1){
                    cnt++;
                }
                else{
                    break;
                }
                neg = !neg;
            }
            if(i!=idx){
                i--;
            }
            maxi = max(maxi ,cnt);
        }

        return maxi==1?-1:maxi;
    }
};