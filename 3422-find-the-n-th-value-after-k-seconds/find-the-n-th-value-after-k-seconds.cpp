class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int>naya(n,1);
        vector<int>prev(n,1);
        int mod=1e9+7;
        while(k--){
            int sum=1;
            for(int i=1;i<n;i++){
                sum=(sum+prev[i])%mod;
                naya[i]=sum;
            }
            prev=naya;
        }
        return naya[n-1]%mod;
    }
};