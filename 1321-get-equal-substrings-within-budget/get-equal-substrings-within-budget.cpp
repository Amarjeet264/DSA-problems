class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int sum=0;
        int maxi=0;
        while(j<s.length()){
            if(s[j]!=t[j]){
                sum+=abs(s[j]-t[j]);
            }
            while(sum>maxCost){
                sum-=abs(s[i]-t[i]);
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};