class Solution {
    
public:
    long long numberOfWays(string s) {
        int n=s.length();
        long n0=0;
        long n1=0;
        long n01=0;
        long n10=0;
        long n101=0;
        long n010=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                n0++;
                n10+=n1;
                n010+=n01;
            }
            else{
                n1++;
                n01+=n0;
                n101+=n10;
            }
        }
        return n010+n101;
    }
};