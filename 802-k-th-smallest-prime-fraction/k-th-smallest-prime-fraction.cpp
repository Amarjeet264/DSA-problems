class Solution {
    int a=0;
    int b=0;
    int count(vector<int>&arr,double mid){
        int i=0;
        int j=1;
        int count=0;
        double maxf=0;
        while(j<arr.size()){
            while(i<j&&(double)arr[i]/arr[j]<=mid){
                i++;
            }
            count+=i;
            if(i>0&&(double)arr[i-1]/arr[j]>maxf){
                maxf=(double)arr[i-1]/arr[j];
                a=arr[i-1];
                b=arr[j];
            }
            j++;
        }
        return count;
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l=(double)arr[0]/arr[arr.size()-1];
        double r=1;
        while(l<r){
            double mid=(l+r)/2;
            if(count(arr,mid)<k){
                l=mid;
            }
            else if(count(arr,mid)>k){
                r=mid;
            }
            else{
                break;
            }
        }
        return {a,b};
    }
};