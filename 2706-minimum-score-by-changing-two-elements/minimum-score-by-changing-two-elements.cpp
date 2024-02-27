class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<=3)return 0;
        int i=1;
        while(i<nums.size()){
            if(nums[i]!=nums[i-1]){
                break;
            }
            i++;
        }
        int j=n-2;
        while(j>=0){
            if(nums[j]!=nums[j+1]){
                break;
            }
            j--;
        }
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        if(i>=j){
            int mini=INT_MIN;
            for(int i=1;i<n;i++){
                mini=max(mini,nums[i]-nums[i-1]);
            }
            return mini;
        }
        if(i==1&&j==n-2){
            int nayasum=nums[n-2]-nums[1];
            nayasum=min(nayasum,nums[n-1]-nums[2]);
            nayasum=min(nayasum,nums[n-3]-nums[0]);
            return nayasum;
        }
        else if(i>1&&j>=n-3){
            return nums[n-3]-nums[0];
        }
        else if(j<=n-3&&i<=2){
            return min(nums[n-1]-nums[i],min(nums[j]-nums[0],nums[n-1]-nums[2]));
        }
        return -1;
    }
};