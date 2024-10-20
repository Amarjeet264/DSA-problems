class Solution {
    long long isposs(long long mid,vector<int>&bat){
        long long time=0;
        for(int i=0;i<bat.size();i++){
            if(bat[i]<=mid){
                time+=bat[i];
            }
            else{
                time+=mid;
            }
        }
        return time;
    }
public:
    long long maxRunTime(int n, vector<int>& bat) {
        int x=bat.size();
        if(n>x){
            return -1;
        }
        long long sum=0;
        for(int i=0;i<x;i++){
            sum+=bat[i];
        }
        long long low=1;
        long long high=sum;
        long long ans=-1;
        while(low<=high){
            long long mid=(low+high)/2;
            long long sum = isposs(mid,bat);
            if(sum>=n*mid){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};