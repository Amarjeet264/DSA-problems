class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans(2);
        int xor2=0;
        for(int i=0;i<nums.size();i++){
            xor2=xor2^nums[i];
        }
        int setb=0;
        for(int i = 0; i<32 ; i++)
        {
            if((xor2 >> i) & 1)
            {
                 setb = i;
                break;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(((nums[i]>>setb)&1)==0){
                ans[0]=ans[0]^nums[i];
            }
            else{
                ans[1]=ans[1]^nums[i];
            }
        }
        return ans;
    }
};