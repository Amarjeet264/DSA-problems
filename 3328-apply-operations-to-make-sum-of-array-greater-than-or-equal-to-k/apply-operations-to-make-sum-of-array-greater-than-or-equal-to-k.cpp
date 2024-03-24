class Solution {
public:
    int minOperations(int k) {
       if(k<=1)return 0;
        int sum=1;
        int cnt=0;
        while(k/sum>sum){
            cnt++;
            sum++;
        }
        int s=sum;
        while(sum<k){
            cnt++;
            sum+=s;
        }
        return cnt;
    }
};