class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0;
        int rem = 0;
        while(numBottles>0){
            cnt += numBottles;
            numBottles += rem;
            int exc = (numBottles/numExchange);
            rem = (numBottles%numExchange);
            numBottles = exc ;
        }
        return cnt;
    }
};