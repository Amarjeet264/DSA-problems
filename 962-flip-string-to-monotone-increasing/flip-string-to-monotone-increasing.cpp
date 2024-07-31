class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        int cnt=0;
        vector<int>right(n);
        vector<int>left(n);
        for(int i=0;i<n;i++){
            left[i]=cnt;
            if(s[i]=='1'){
                cnt++;
            }
        }
        int mini = INT_MAX;
        mini=min(mini,cnt);
        mini=min(mini,n-cnt);
        cnt = 0;
        for(int i=n-1;i>=0;i--){
            right[i]=cnt;
            if(s[i]=='0'){
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            // cout<<right[i]<<" ";
            if(s[i]=='0'){
                mini = min(mini,1+right[i]+left[i]);
            }
            else{
                mini = min(mini,right[i]+left[i]);
            }
        }
        return mini;
    }
};