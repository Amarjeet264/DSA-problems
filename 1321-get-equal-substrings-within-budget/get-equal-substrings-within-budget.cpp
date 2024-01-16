class Solution {
    bool isposs(int len,int cost,string s,string t){
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<s.length()){
            if(s[j]!=t[j]){
                cost-=abs(s[j]-t[j]);
                if(cost<0){
                    while(i<=j&&cost<0){
                        cost+=abs(s[i]-t[i]);
                        i++;
                    }
                }
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen>=len;
    }
public:
    int equalSubstring(string s, string t, int maxC) {
        int low=0;
        int high=s.length()+1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isposs(mid,maxC,s,t)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};