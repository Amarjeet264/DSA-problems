class Solution {
    int place1(string s,char ch){
        int i=0;
        bool one=true;
        int cnt=0;
        while(i<s.size()){
            if(one){
                if(s[i]!=ch){
                    cnt++;
                }
            }
            one=!one;
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
            return place1(s,'0');
        }
        else if(cnt1>cnt0){
            return place1(s,'1');
        }
        return min(place1(s,'1'),place1(s,'0'));
    }
};