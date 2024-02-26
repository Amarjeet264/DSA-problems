class Solution {
public:
    int minDeletion(vector<int>& nums) {
        vector<int>ans;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if((i-cnt)%2==0&&nums[i]==nums[i+1]){
                // cout<<i<<" ";
                cnt++;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        if((nums.size()-cnt)%2!=0){
            cnt++;
        }
        return cnt;
    }
};