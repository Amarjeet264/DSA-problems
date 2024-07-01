class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int cnt = 0;
        vector<int>flip_Count(nums.size(),0);
        bool zero = 0;
        int flips = 0;
        for(int i = 0; i < nums.size()-k+1; i++){
            if(nums[i] == 0 ){
                if(flips % 2 == 0){
                    flip_Count[i]++;
                    flip_Count[i+k-1]--;
                    cnt++;
                }
            }
            else{
                if(flips%2){
                    flip_Count[i]++;
                    flip_Count[i+k-1]--;
                    cnt++;
                }
            }
            flips+=flip_Count[i];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero=1;
            }
        }
        for(int i=nums.size()-k+1;i<nums.size();i++){
            if(nums[i]==1&&flips%2){
                return -1;
            }
            else {
                if(nums[i]==0&&flips%2==0){
                    return -1;
                }
            }
            flips+=flip_Count[i];
        }
        if(cnt==0&&zero==1)return -1;
        return cnt;
    }
};