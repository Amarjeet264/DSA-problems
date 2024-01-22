class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int rep=-1;
       int mis=-1;
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
           if(mp.find(nums[i])!=mp.end()){
               rep=nums[i];
           }
           mp[nums[i]]++;
       }
       for(int i=1;i<=nums.size();i++){
           if(mp.find(i)==mp.end()){
               mis=i;
           }
       }
       if(mis==-1){
           mis=nums.size()+1;
       }
       return {rep,mis};
    }
};