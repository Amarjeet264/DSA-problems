class Solution {
public:
    int maximumSwap(int num) {
        int ans=num;
        string s="";
        while(num){
            int x=num%10;
            s+=(x+'0');
            num/=10;
        }
        reverse(s.begin(),s.end());
        // cout<<s<<" ";
        int i=s.size()-1;
        int maxi=i;
        int idx=-1;
        int swapidx=-1;
        while(i>=0){
            if(s[i]-'0'<s[maxi]-'0'){
                idx=i;
                swapidx=maxi;
            }
            if(s[maxi]-'0'<s[i]-'0'){
                maxi=i;
            }
            i--;
        }
        if(idx!=-1){
            swap(s[idx],s[swapidx]);
            ans=0;
            int i=0;
            while(i<s.size()){
                ans=ans*10+(s[i]-'0');
                i++;
            }
        }
        // cout<<s<<" ";
        return ans;
    }
};