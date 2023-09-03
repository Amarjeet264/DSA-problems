class Solution {
public:
    int minimumOperations(string num) {
        int mini=INT_MAX;
        // int x=stoi(num);
        // if(x<25){
        //     if(x==10||x==20||num.length()<2){
        //         return 1;
        //     }
        //     return 2;
        // }
        for(int i=num.length()-1;i>=0;i--){
            if(num[i]=='0'){
                int x=i-1;
                int cnt=0;
                while(x>=0&&num[x]!='5'&&num[x]!='0'){
                    x--;
                    cnt++;
                }
                if(x>=0&&mini>num.length()-i-1+cnt){
                    mini=num.length()-i-1+cnt;
                }
                else if(x<0&&mini>num.length()-1){
                    mini=num.length()-1;
                }
            }
            else if(num[i]=='5'){
                int x=i-1;
                int cnt=0;
                while(x>=0&&num[x]!='7'&&num[x]!='2'){
                    x--;
                    cnt++;
                }
                if(x>=0&&mini>num.length()-i-1+cnt){
                    mini=num.length()-i-1+cnt;
                }
            }
        }
        if(mini==INT_MAX)return num.length();
        return mini;
    }
};