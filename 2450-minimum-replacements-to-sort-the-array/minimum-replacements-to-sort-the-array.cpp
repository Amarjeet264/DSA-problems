class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[n-1];
        long long int ans=0;
        for(int i=n-2;i>=0;i--){
            if(prev<nums[i]){
                long long tot=nums[i]/prev;
                if(nums[i]%prev!=0){
                    tot++;
                    prev=nums[i]/tot;
                    // cout<<tot<<" "<<prev<<endl;
                }
                ans+=tot-1;
            }
            else{
                prev=nums[i];
            }
        }
        return ans;
    }
};