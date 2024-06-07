class Solution {
    int place1(string s){
        int i=0;
        bool one=true;
        int cnt=0;
        while(i<s.size()){
            if(one){
                if(s[i]!='1'){
                    cnt++;
                }
            }
            one=!one;
            i++;
        }
        return cnt;
    }
    int place0(string s){
        int i=0;
        int cnt=0;
        bool zero=true;
        while(i<s.size()){
            if(zero){
                if(s[i]!='0'){
                    cnt++;
                }
            }
            zero=!zero;
            i++;
        }
        return cnt;
    }
public:
    int minSwaps(string s) {
        int cnt1=0;
        int cnt0=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
        }
        if(abs(cnt0-cnt1)>1){
            return -1;
        }
        if(cnt0>cnt1){
            return place0(s);
        }
        else if(cnt1>cnt0){
            return place1(s);
        }
        return min(place1(s),place0(s));
    }
};