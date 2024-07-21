class Solution {
public:
    int minChanges(int n, int k) {
        int cnt=0;
        while(n||k){
            if(n%2!=k%2){
                if(n&1){
                    cnt++;
                }
                else{
                    return -1;
                }
            }
            n>>=1;
            k>>=1;
        }
        return cnt;
    }
};