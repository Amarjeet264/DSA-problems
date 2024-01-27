class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int cnt=0;
        for(auto &it:mp){
            if(it.second==1){
                return -1;
            }
            int x=it.second;
            int z=x/3;
            x=x-3*z;
            if(x==1){
                z++;
            }
            if(x%2==0){
                z+=x/2;
            }
            cout<<it.first<<" "<<z<<endl;
            cnt+=z;
        }
        return cnt;
    }
};