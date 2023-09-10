class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdiff=abs(sx-fx);
        int ydiff=abs(sy-fy);
        if(t==1&&sx==fx&&sy==fy){
            return false;
        }
        if(max(xdiff,ydiff)>t)return false;
        return true;
    }
};