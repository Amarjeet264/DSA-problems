class Solution {

public:
   typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        long long xXora = 0;
        long long xXorb = 0;
        for(ll i=49;i>=n;i--){
            bool bit_a = ((a>>i)&1)>0;
            bool bit_b = ((b>>i)&1)>0;
            if(bit_a)xXora = (xXora^(1ll<<i));
            if(bit_b)xXorb = (xXorb^(1ll<<i));
        }
        for(ll i=n-1;i>=0;i--){
            bool bit_a = (a>>i)&1;
            bool bit_b = (b>>i)&1;
            if(bit_a==bit_b){
                xXora ^= (1ll<<i);
                xXorb ^= (1ll<<i);
            }
            else{
                if(xXora>xXorb){
                    xXorb ^= (1ll<<i);
                }
                else{
                    xXora ^= (1ll<<i);
                }
            }
        }
        int mod = 1e9+7;
        xXora%=mod;
        xXorb%=mod;
        return (xXora*xXorb)%mod;
    }
};