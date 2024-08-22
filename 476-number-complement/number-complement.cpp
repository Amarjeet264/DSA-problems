class Solution {
public:
    int findComplement(int num) {
        int comp = 0;
        int pp = 0;
        while(num){
            if(num%2==0){
                comp = comp + pow(2,pp);
            }
            pp++;
            num/=2;
        }
        return comp;
    }
};