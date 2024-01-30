class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
       int ans=0;
       for(int i=0;i<nums.size();i++){
           unordered_map<int,int>mp;
           for(int j=i;j<nums.size();j++){
               mp[j]++;
               int prev=-1;
               bool can=1;
               for(int k=0;k<nums.size();k++){
                   if(mp.find(k)==mp.end()){
                       if(nums[k]<=prev){
                           can=0;
                       }
                       prev=nums[k];
                   }
               }
               if(can){
                   ans++;
               }
           }
       }
       return ans;
    }
};