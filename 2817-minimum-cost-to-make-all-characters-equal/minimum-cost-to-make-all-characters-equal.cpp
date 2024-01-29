class Solution {
public:
    long long minimumCost(string s) {
        long long ans=0;
        if(s.length()<2){
            if(s.length()<=1){
                return 0;
            }
            else{
                if(s[0]!=s[1]){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        for(int i=0;i<=s.length()-2;i++){
            if(s[i]!=s[i+1]){
                ans+=min(i+1,(int)s.size()-i-1);
            }
        }
        return ans;
    }
};