class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        int i=0;
        while(i<j){
            if(nums[i]>0||nums[j]<0){
                break;
            }
            else if(abs(nums[i])==nums[j]){
                return nums[j];
            }
            else if(abs(nums[i])>nums[j]){
                i++;
            }
            else if(abs(nums[i])<nums[j]){
                j--;
            }
        }
        return -1;
        // int lastneg=-1;
        // for(int i=nums.size()-1;i>=0;i--){
        //     if(nums[i]<0){
        //         lastneg=i;
        //         break;
        //     }
        // }
        // int firstpos=lastneg+1;

    }
};