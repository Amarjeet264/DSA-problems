class Solution {
    bool isposs(int mid,vector<int>&price,int k){
       int prev=price[0];
       int cnt=1;
       for(int i=1;i<price.size();i++){
           if(price[i]-prev>=mid){
               cnt++;
               prev=price[i];
           }
       }
       return cnt>=k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int low=0;
        int high=price[price.size()-1]-price[0];
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isposs(mid,price,k)){
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