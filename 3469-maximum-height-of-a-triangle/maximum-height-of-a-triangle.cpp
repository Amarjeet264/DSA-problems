class Solution {
    int calc(int red,int blue){
        bool re=true;
        int cnt=0;
        int x=1;
        while(red>0||blue>0){
            if(re){
                if(red>=x){
                    cnt++;
                    red-=x;
                    re=!re;
                }
                else{
                    break;
                }
            }
            else{
                if(blue>=x){
                    cnt++;
                    blue-=x;
                    re=!re;
                }
                else{
                    break;
                }
            }
            x++;
        }
        return cnt;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(calc(blue,red),calc(red,blue));
    }
};