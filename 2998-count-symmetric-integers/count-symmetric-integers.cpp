class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.length()%2)continue;
            int sumleft=0;
            for(int k=0;k<s.length()/2;k++){
                sumleft+=(int)s[k];
            }
            int sumright=0;
            for(int k=s.length()-1;k>=s.length()/2;k--){
                sumright+=(int)s[k];
            }
            if(sumleft==sumright)cnt++;
        }
        return cnt;
    }
};