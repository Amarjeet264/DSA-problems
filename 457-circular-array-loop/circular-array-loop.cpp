class Solution {
    bool topo(unordered_map<int,int>&mp,int x,int n){
        for(auto it:mp){
            int slow=it.first;
            int fast=it.first;
            int cnt=0;
            while(cnt<2*n){
                cnt++;
                if(mp.find(slow)==mp.end()){
                     continue;
                }
                slow=mp[slow];
                if(mp.find(fast)==mp.end()){
                     continue;
                }
                fast=mp[fast];
                if(mp.find(fast)==mp.end()){
                     continue;
                }
                fast=mp[fast];
                if(slow==fast){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        unordered_map<int,int>mp;
        int x=-1;
        int y=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)continue;
            // if(i+nums[i]<nums.size()){
                if(i!=(i+nums[i])%nums.size())
                   mp[i]=(i+nums[i])%nums.size();
            // }
        }
        for(auto it:mp){
            cout<<it.first<<"->"<<it.second<<endl;
        }
        cout<<endl;
        unordered_map<int,int>mp1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)continue;
            if(i+nums[i]>=0&&i!=(i+nums[i])%nums.size()){
                mp1[i]=(i+nums[i])%nums.size();
            }
            else{
                if(i!=(nums.size()+(i+nums[i]))%nums.size())
                   mp1[i]=(nums.size()+(i+nums[i]))%nums.size();
            }
        }
        for(auto it:mp1){
            cout<<it.first<<"->"<<it.second<<endl;
        }
        return topo(mp1,y,nums.size())||topo(mp,x,nums.size());
    }
};