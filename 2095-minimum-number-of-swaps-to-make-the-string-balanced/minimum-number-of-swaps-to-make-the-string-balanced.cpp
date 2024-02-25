class Solution {
public:
    int minSwaps(string s) {
        int cnt=0;
        int close=0;
        int open=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                close++;
            }
            else{
                open++;
            }
            // if(open==close){
            //     ans+=(ceil(cnt/2.0));
            // }
            if(open<close){
                cnt++;
                open=0;
                close=0;
            }
        }
        // if(open==close){
        //     ans+=(ceil(cnt/2.0));
        // }
        return ceil(cnt/2.0);
    }
};