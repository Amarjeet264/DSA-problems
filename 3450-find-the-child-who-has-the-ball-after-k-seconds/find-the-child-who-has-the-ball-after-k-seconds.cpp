class Solution {
public:
    int numberOfChild(int n, int k) {
        bool ltor=true;
        int i=0;
        while(k--){
            if(ltor){
                i++;
            }
            else{
                i--;
            }
            if(i==n-1){
                ltor=0;
            }
            else if(i==0){
                ltor=1;
            }
        }
        return i;
    }
};