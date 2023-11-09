class Solution {
public:
    int countHomogenous(string s) {
        char prev='#';
        int i=0;
        int j=0;
        int ans=0;
        int cnt=0;
        int mod=1e9+7;
        while(j<s.length()){
            if(prev=='#'){
                prev=s[j];
                j++;
            }
            else if(prev==s[j]){
                j++;
            }
            else{
                ans=(ans+((j-i)*(j-i+1))/2)%mod;
                prev=s[j];
                i=j;
                j++;
            }
        }
        // cout<<ans<<" "<<i;
        // if(i!=s.length()-1){
            ans=(ans+((s.length()-i)*(s.length()-i+1))/2)%mod;
        // }
        return ans;
    }
};