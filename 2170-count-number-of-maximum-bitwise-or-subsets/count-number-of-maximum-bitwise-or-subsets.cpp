class Solution {
    int count(vector<int>&nums,int i,int maxi,int maxor){
        if(i>=nums.size()){
            if(maxor==maxi){
                return 1;
            }
            return 0;
        }
        if(maxor>maxi)return 0;
        int nottake = count(nums,i+1,maxi,maxor);
        int take = 0;
        if(maxor<=maxi)take = count(nums,i+1,maxi,maxor|nums[i]);
        return take+nottake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            maxi = maxi|nums[i];
        }
        cout<<maxi;
        return count(nums,0,maxi,0);
    }
};