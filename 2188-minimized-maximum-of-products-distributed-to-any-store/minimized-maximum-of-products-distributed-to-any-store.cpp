class Solution {
    bool isposs(int mid,vector<int>&arr,int n){
        int cnt = 0;
        for(int i=0;i<arr.size();i++){
            cnt += ceil(1.0*arr[i]/mid);
        }
        return cnt<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& qua) {
        long long high = 0;
        for(int i=0;i<qua.size();i++){
            high+= qua[i];
        }
        long long low = 1;
        long long ans = 0;
        while(low<=high){
            long long mid = (low+high)/2;
            if(isposs(mid,qua,n)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};