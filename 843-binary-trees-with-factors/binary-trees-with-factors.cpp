class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0&&mp.find(arr[i]/arr[j])!=mp.end()){
                    mp[arr[i]]+=mp[arr[j]]*mp[arr[i]/arr[j]];
                }
            }
        }
        long res=0;
        for(auto it:mp){
            res+=it.second;
        }
        return res%(int)(1e9+7);
    }
};