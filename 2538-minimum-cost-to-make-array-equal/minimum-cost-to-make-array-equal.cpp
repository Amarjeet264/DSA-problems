class Solution {
    long long cost1(vector<int>&nums,vector<int>&cost,int m){
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans+(abs((long long)nums[i]-(long long)m)*(long long)cost[i]);
        }
        return ans;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long mini=nums[0];
        long long maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            mini=min(mini,(long long)nums[i]);
            maxi=max(maxi,(long long)nums[i]);
        }
        long long ans=0;
        long long low=mini;
        long long high=maxi;
        while(low<=high){
            long long mid=(high+low)/2;
            long long calc1=cost1(nums,cost,mid);
            long long calc2=cost1(nums,cost,mid+1);
            if(calc1<calc2){
                ans=calc1;
                high=mid-1;
            }
            else{
                ans=calc2;
                low=mid+1;
            }
        }
        return ans;
    }
};