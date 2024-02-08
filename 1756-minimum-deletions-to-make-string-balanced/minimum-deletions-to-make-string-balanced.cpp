class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int>makea(n,1e5);
        vector<int>makeb(n,1e5);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                cnt++;
            }
            makea[i]=cnt;
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                cnt++;
            }
            makeb[i]=cnt;
        }
        int mini=n-1;
        for(int i=0;i<n;i++){
            int x=0;
            int y=0;
            x=makea[i];
            y=makeb[i];
            mini=min(mini,x+y-1);
        }
        return mini;
    }
};