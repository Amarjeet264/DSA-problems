class Solution {
    int count(int x,int m,int n,int k){
        int count=0;
        for(int i=1;i<=m;i++){
          count+=min(x/i,n);
        }
        return count;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int low=0;
        int high=m*n;
        while(low<high){
            int mid=(low+high)/2;
            int x=count(mid,m,n,k);
            if(x+1<=k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};