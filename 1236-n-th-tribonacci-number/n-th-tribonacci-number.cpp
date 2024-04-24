class Solution {
public:
    int tribonacci(int n) {
       int x=0;
       int y=1;
       int z=1;
       if(n<3){
        if(n==0){
            return 0;
        }
        else{
            return 1;
        }
       }
       int ans=-1;
       for(int i=3;i<=n;i++){
        ans=x+y+z;
        x=y;
        y=z;
        z=ans;
       } 
       return ans;
    }
};