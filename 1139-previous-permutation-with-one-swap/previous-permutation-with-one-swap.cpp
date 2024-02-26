class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size();
        int idx=-1;
        for(int i=n-1;i>0;i--){
            if(arr[i-1]>arr[i]){
                idx=i;
                break;
            }
        }
        // cout<<idx<<" ";
        if(idx==-1)return arr;
        int maxidx=-1;
        int maxi=INT_MIN;
        for(int i=idx;i<n;i++){
            if(maxi<arr[i]&&arr[i]<arr[idx-1]){
                maxidx=i;
                maxi=arr[i];
            }
        }
        swap(arr[idx-1],arr[maxidx]);
        return arr;
    }
};