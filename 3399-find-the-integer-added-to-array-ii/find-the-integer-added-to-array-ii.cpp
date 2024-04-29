class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>mp;
       for(auto it:nums1){
         mp[it]++;
       }
       int mini=INT_MAX;
       for(int i=0;i<=1000;i++){
            unordered_map<int,int>mp1=mp;
            int cnt=0;
            for(auto it:nums2){
                if(mp1.find(it+i)!=mp1.end()){
                    mp1[it+i]--;
                    if(mp1[it+i]==0){
                        mp1.erase(it+i);
                    }
                    cnt++;
                }
            }
            if(cnt==nums2.size()){
            //     return -i;
                mini=min(mini,-i);
            }
            cnt=0;
            mp1=mp;
            for(auto it:nums2){
                if(mp1.find(it-i)!=mp1.end()){
                    mp1[it-i]--;
                    if(mp1[it-i]==0){
                        mp1.erase(it-i);
                    }
                    cnt++;
                }
            }
            if(cnt==nums2.size()){
                // return i;
                mini=min(mini,i);
            }
       }
       return mini;
    }
};