class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       long long int i=0;
       long long int j=0;
       long long int sum=0;
       long long int maxi=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(nums[j]*(j-i+1)<=sum+k){
                maxi=max(maxi,j-i+1);
            }
            else if(nums[j]*(j-i+1)>sum+k){
                while(nums[j]*(j-i+1)>sum+k){
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }
};