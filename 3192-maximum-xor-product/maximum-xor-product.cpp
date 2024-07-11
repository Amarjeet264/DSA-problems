#include <iostream>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        long long xXora = 0;
        long long xXorb = 0;
        
        // Iterate through the bits from the most significant to the least significant
        for (int i = 49; i >= n; --i) {
            bool bit_a = (a >> i) & 1;
            bool bit_b = (b >> i) & 1;
            xXora = (xXora << 1) | bit_a;
            xXorb = (xXorb << 1) | bit_b;
        }
        
        for (int i = n-1; i >= 0; --i) {
            bool bit_a = (a >> i) & 1;
            bool bit_b = (b >> i) & 1;
            
            if (bit_a == bit_b) {
                xXora = (xXora << 1) | 1;
                xXorb = (xXorb << 1) | 1;
            } else {
                if (xXora > xXorb) {
                    xXorb = (xXorb << 1) | 1;
                    xXora = (xXora << 1);
                } else {
                    xXora = (xXora << 1) | 1;
                    xXorb = (xXorb << 1);
                }
            }
        }
        
        int mod = 1e9 + 7;
        xXora %= mod;
        xXorb %= mod;
        return (xXora * xXorb) % mod;
    }
};
