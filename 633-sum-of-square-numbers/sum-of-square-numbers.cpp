class Solution {
public:
    bool judgeSquareSum(int c) {
        int start=0;
        int end=sqrt(c);
        while(start<=end){
            long long sum=start*start;
            long long x=c-(end*end);
            if(sum==x){
                return true;
            }
            else if(sum<x){
                start++;
            }
            else{
                end--;
            }
        }
        return 0;
    }
};