class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[n-1];
        long long int ans=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>prev){
                long long int tot=(nums[i]-1)/prev;
                cout<<tot<<" ";
                prev=nums[i]/(tot+1);
                cout<<prev<<" ";
                ans+=tot;
            }
            else{
                prev=nums[i];
            }
        }
        return ans;
    }
};