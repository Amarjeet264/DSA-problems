class Solution {
public:
    long long minimumSteps(string s) {
        int i=0;
        int firstone=-1;
        long long cnt=0;
        while(i<s.size()){
            if(s[i]=='1'){
                if(firstone==-1){
                    firstone=i;
                }
                i++;
            }
            else{
                if(firstone==-1){
                    i++;
                    continue;
                }
                else{
                    // int j=i;
                    // while(j>firstone){
                    //     swap(s[j],s[j-1]);
                        cnt+=(i-firstone);
                    //     j--;
                    // }
                    firstone=firstone+1;
                    i++;
                }
            }
        }
        return cnt;
    }
};