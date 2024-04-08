class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long cnt=0;
        int n=nums.size();
        if(nums.size()%2!=0){
            for(int i=0;i<n;i++){
                cout<<nums[i]<<" ";
                if(i==n/2&&nums[i]!=k){
                    cnt+=abs(k-nums[i]);
                    nums[i]=k;
                    continue;
                }
                if(i<n/2&&k<=nums[i]){
                    cnt+=(nums[i]-k);
                    nums[i]=k;
                }
                else if(i>n/2&&nums[i]<k){
                    cnt+=(k-nums[i]);
                }
            }
        }
        else{
            for(int i=0;i<(n/2)-1;i++){
                // cout<<nums[i]<<" ";
                if(nums[i]>=k){
                    cnt+=(nums[i]-k);
                }
            }
            if(nums[n/2]<k||nums[n/2]>k){
                cnt+=abs(nums[n/2]-k);
                if(nums[n/2-1]>k){
                    cnt+=(nums[n/2-1]-k);
                }
            }
            for(int i=n/2+1;i<n;i++){
                if(nums[i]<k){
                    cnt+=(k-nums[i]);
                }
            }
        }
        return cnt;
    }
};