class Solution {
    long long howMany(long long a,long long b,int mod){
        long long ans = 1;
        while(b>0){
            if(b&1){
                ans = ans*a%mod;
                b-=1;
            }
            if(b>0){
                a = a*a%mod;
            }
            b/=2;
        }
        return ans;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        if(multi == 1){
            return nums;
        }
        set<pair<long long,int>>st;
        for(int i = 0;i<nums.size();i++){
            st.insert({nums[i],i});
        }
        while(k>0){
            if(st.begin()->first*multi>st.rbegin()->first){
                break;
            }
            auto  it = st.begin();
            long long naya = it->first*multi;
            int idx = it->second;
            st.erase(st.begin());
            st.insert({naya,idx});
            k--;
        }
        int mod = 1e9+7;
        if(k==0){
            vector<int>ans(nums.size());
            for(auto it:st){
                ans[it.second] = it.first%mod;
            }
            return ans;
        }
        long long times = k/nums.size();
        long long extra = k%nums.size();
        int p = howMany(multi,times,mod)%mod;
        int i = 0;
        vector<int>ans(nums.size());
        for(auto it:st){
            long long currFinal = (p * it.first) % mod;  // Ensure multiplication is done in long long
            if (i < extra) {
                currFinal = (currFinal * multi) % mod;
            }
            ans[it.second] = currFinal;
            i++;
        }
        return ans;
    }
};