class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            string x="";
            if(target.substr(0,nums[i].size())==nums[i]&&nums[i].size()<target.size())x=target.substr(nums[i].size(),target.size()-nums[i].size());
            // cout<<nums[i]<<" "<<x<<endl;
            if(x==nums[i]){
                cnt+=mp[x]-1;
            }
            else if(x!=""){
                cnt+=mp[x];
            }
            cout<<cnt<<endl;
        }
        return cnt;
    }
};