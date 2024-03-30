class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long cnt=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int i=0;
        int j=0;
        int freq=0;
        while(j<nums.size()){
            if(nums[j]==maxi){
                freq++;
            }
            while(i<=j&&freq>=k){
                if(nums[i]==maxi){
                    freq--;
                }
                cnt+=(nums.size()-j);
                i++;
            }
            j++;
        }
        return cnt;
    }
};