class Solution {
    int a=0;
    int b=0;
    int count(vector<int>&arr,double mid){
        int res = 0;
        for (int i = 0, j = 0; i < arr.size(); i++) {
            while (j < i && (double)arr[j + 1] / arr[i] <= mid) j++;
            if ((double)arr[j] / arr[i] <= mid) res += j + 1;
            if (fabs((double)arr[j] / arr[i] - mid) < 1e-8) {
                a = arr[j], b = arr[i];
            }
        }
        return res;
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l=0;
        double r=1;
        while(r-l>1e-8){
            double mid=(l+r)/2;
            if(count(arr,mid)>=k){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        return {a,b};
    }
};