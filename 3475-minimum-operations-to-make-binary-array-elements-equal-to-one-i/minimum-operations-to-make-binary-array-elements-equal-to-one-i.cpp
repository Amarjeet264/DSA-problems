class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int k=3;
        vector<int>flip_Count(nums.size(),0);
        bool zero = 0;
        int flips = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 ){
                if(flips % 2 == 0){
                    if(i+k>nums.size())return -1;
                    flip_Count[i]++;
                    flip_Count[i+k-1]--;
                    cnt++;
                }
            }
            else{
                if(flips%2){
                    if(i+k>nums.size())return -1;
                    flip_Count[i]++;
                    flip_Count[i+k-1]--;
                    cnt++;
                }
            }
            flips+=flip_Count[i];
        }
        
        return cnt;
    }
};