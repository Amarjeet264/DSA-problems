class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        vector<bool>odd(n,0);
        vector<bool>even(n,0);
        odd[n-1]=1;
        even[n-1]=1;
        map<int,int>mp;
        int cnt=1;
        mp[arr[n-1]]=n-1;
        for(int i=n-2;i>=0;i--){
            auto oddjump=mp.lower_bound(arr[i]);
            auto evenjump=mp.upper_bound(arr[i]);
            if(oddjump!=mp.end()){
                odd[i]=even[oddjump->second];
            }
            if(evenjump!=mp.begin()){
                evenjump--;
                even[i]=odd[evenjump->second];
            }
            if(odd[i]){
                cnt++;
            }
            mp[arr[i]]=i;
        }
        return cnt;
    }
};