class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0;
        int count10=0;
        int N=bills.size();
        for(int i=0;i<N;i++){
            if(bills[i]==5){
                count5++;
            }
            else if(bills[i]==10){
                count10++;
                count5--;
            }
            else{
                if(count10>0){
                   count10--;
                   count5--;
                }
                else{
                    count5-=3;
                }
            }
            if(count10<0||count5<0){
                return 0;
            }
        }
        return 1;
    }
};