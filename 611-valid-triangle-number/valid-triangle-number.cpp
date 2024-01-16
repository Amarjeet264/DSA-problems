class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i+1;j<nums.size();j++){
                sum=nums[i]+nums[j];
                int low=j+1;
                int high=nums.size()-1;
                int temp=-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(nums[mid]>=sum){
                        high=mid-1;
                    }
                    else{
                        temp=mid;
                        low=mid+1;
                    }
                }
                if(temp!=-1)ans+=(temp-j);
            }
        }
        return ans;
    }
};