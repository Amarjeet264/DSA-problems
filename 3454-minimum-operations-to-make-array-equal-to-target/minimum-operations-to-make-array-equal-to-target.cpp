class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long prev = 0;
        long long cnt = 0;
        for(int i=0;i<nums.size();i++){
            long long curr = target[i] - nums[i];
            if((curr<0&&prev>0)||(curr>0&&prev<0)){
                cnt += abs(curr);
            }
            else{
                if(abs(curr)>abs(prev)){
                    cnt+=abs(curr-prev);
                }
            }
            prev = curr;
        }
        return cnt;
    }
};