class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0;
        int z=x;
        while(x){
            sum+=x%10;
            x=x/10;
        }
        if(z%sum)return -1;
        return sum;
    }
};