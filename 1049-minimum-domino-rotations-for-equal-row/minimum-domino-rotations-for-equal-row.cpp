class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int can1=tops[0];
        int can2=bottoms[0];
        int top1=0;
        int bottom1=0;
        int top2=0;
        int bottom2=0;
        bool c1=1;
        bool c2=1;
        int ans=INT_MAX;
        for(int i=0;i<tops.size();i++){
            if(can1!=tops[i]&&can1!=bottoms[i]){
                c1=0;
            }
            else if(can1!=tops[i]){
                top1++;
            }
        }
        if(c1){
            ans=top1;
        }
        for(int i=0;i<tops.size();i++){
            if(can2!=tops[i]&&can2!=bottoms[i]){
                c2=0;
            }
            else if(can2!=tops[i]){
                top2++;
            }
        }
        if(c2){
            ans=min(ans,top2);
        }
        if(!c1&&!c2)return -1;

        for(int i=0;i<bottoms.size();i++){
            if(can1!=tops[i]&&can1!=bottoms[i]){
                c1=0;
            }
            else if(bottoms[i]!=can1){
                bottom1++;
            }
        }
        if(c1){
            ans=min(ans,bottom1);
        }
        for(int i=0;i<bottoms.size();i++){
            if(can2!=tops[i]&&can2!=bottoms[i]){
                c2=0;
            }
            else if(bottoms[i]!=can2){
                bottom2++;
            }
        }
        if(c2){
            ans=min(ans,bottom2);
        }
        return ans;
    }
};