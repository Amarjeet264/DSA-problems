class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        vector<int>left(n,0);
        vector<int>right(n,0);
        int cnt=0;
        int mini=n;
        for(int i=0;i<n;i++){
            left[i]=cnt;
            if(s[i]=='0'){
                cnt++;
            }
        }
        // cout<<mini<<" ";
        mini=min(mini,cnt);
        mini=min(mini,n-cnt);
        cnt=0;
        for(int i=n-1;i>=0;i--){
            right[i]=cnt;
            if(s[i]=='0'){
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            mini=min(mini,i-left[i]+right[i]);
        }
        return mini;
    }
};