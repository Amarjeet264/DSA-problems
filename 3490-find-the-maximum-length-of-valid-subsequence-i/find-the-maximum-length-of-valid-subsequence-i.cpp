class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int even = -1;
        int odd = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                if(even == -1){
                    even = i;
                }
            }
            else {
                if(odd == -1){
                    odd = i;
                }
            }
        }
        int maxi = 0;
        int cnt=0;
        for(int i = even+1 ;i<nums.size();i++){
            if(nums[i]%2==0){
                cnt++;
            }
        }
        maxi = cnt + 1;
        cnt=0;
        for(int i = odd+1 ;i<nums.size();i++){
            if(nums[i]%2){
                cnt++;
            }
        }
        maxi=max(maxi,cnt+1);
        cnt=0;
        bool od = 1;
        for(int i = even+1;i<nums.size();i++){
            if(od&&nums[i]%2){
                od=!od;
                cnt++;
            }
            else if(nums[i]%2==0&&!od){
                od=!od;
                cnt++;
            }
        }
        maxi=max(maxi,cnt+1);
        cnt=0;
        bool eve=1;
        for(int i=odd+1;i<nums.size();i++){
            if(eve&&nums[i]%2==0){
                eve=!eve;
                cnt++;
            }
            else if(!eve&&nums[i]%2){
                cnt++;
                eve=!eve;
            }
        }
        maxi=max(maxi,cnt+1);
        return maxi;
    }
};