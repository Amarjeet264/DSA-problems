class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            // int x=(k-abs(arr[i])%k)%k;
            int z=arr[i]%k;
            if(z<0){
                z+=k;
            }
            int x=(k-z)%k;
            if(mp.find(x)!=mp.end()){
                // cout<<i<<" ";
                mp[x]--;
                if(mp[x]==0){
                    mp.erase(x);
                }
            }
            else{
                mp[z]++;
            }
        }
        // cout<<(-2%3);
        return mp.size()==0;
    }
};