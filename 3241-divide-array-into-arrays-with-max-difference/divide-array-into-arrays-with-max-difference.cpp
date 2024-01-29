class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      vector<vector<int>>ans;
    vector<int>dup;
      for(int i=0;i<nums.size();i++){
         if(dup.size()==0)dup.push_back(nums[i]);
          else{
              if(nums[i]-dup[0]<=k){
                  dup.push_back(nums[i]);
              }
              else{
                  return {};
              }
          }
          if(dup.size()==3){
              ans.push_back(dup);
              while(dup.size()>0){
                  dup.pop_back();
              }
          }
      }
      return ans;   
    }
};