class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        if(k>=n){
            return maxi;
        }
        int i=0;
        int j=1;
        int cnt=0;
        int prev=-1;
        while(j<arr.size()){
            if(arr[j]>arr[i]){
                if(prev!=-1&&arr[prev]==arr[j]){
                    cnt++;
                }
                else{
                    cnt=1;
                    prev=j;
                }
                if(cnt==k){
                    return arr[j];
                }
                i=j;
                j++;
            }
            else{
                if(prev!=-1&&arr[i]==arr[prev]){
                    cnt++;
                }
                else{
                    cnt=1;
                    prev=i;
                }
                if(cnt==k){
                    return arr[i];
                }
                j++;
            }
            if(j==n){
                return max(arr[i],arr[n-1]);
            }
        }
        return arr[n-1];
    }
};