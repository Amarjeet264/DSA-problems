class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        sort(hap.begin(),hap.end());
        int cnt=0;
        long long sum=0;
        int i=hap.size()-1;
        while(i>=0&&k>0){
            if(hap[i]>cnt){
                sum+=(hap[i]-cnt);
            }
            else{
                break;
            }
            cnt++;
            k--;
            i--;
        }
        return sum;
    }
};