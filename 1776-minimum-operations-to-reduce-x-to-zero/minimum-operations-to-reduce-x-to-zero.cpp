class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }
        int target=tot-x;
        if(target==0)return n;
        int maxi=0;
        int i=0;
        int j=0;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            while(i<=j&&sum>target){
                sum-=nums[i];
                i++;
            }
            if(sum==target){
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
        if(maxi==0)return -1;
        return n-maxi;
    }
};