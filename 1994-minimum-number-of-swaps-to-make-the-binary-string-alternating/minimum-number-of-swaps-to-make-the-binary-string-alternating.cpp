class Solution {
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
        int cnt=0;
        // cout<<cnt0<<" "<<cnt1<<endl;
        if(cnt0>cnt1){
            int i=0;
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
        }
        else if(cnt1>cnt0){
            int i=0;
            bool one=true;
            while(i<s.size()){
                if(one){
                    if(s[i]!='1'){
                        cnt++;
                    }
                }
                one=!one;
                i++;
            }
        }
        else{
                int mini=0;
                int i=0;
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
                cout<<cnt<<" ";
                mini=cnt;
                cnt=0;
    
                i=0;
                bool one=true;
                while(i<s.size()){
                    if(one){
                        if(s[i]!='1'){
                            cnt++;
                        }
                    }
                    one=!one;
                    i++;
                }
                if(cnt<mini){
                    mini=cnt;
                }
                return mini;
        }
        return cnt;
    }
};