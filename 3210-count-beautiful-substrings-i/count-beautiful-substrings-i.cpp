class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n=s.length();
        vector<int>cons(n,0);
        vector<int>vow(n,0);
        int v=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                v++;
            }
            else{
                c++;
            }
            vow[i]=v;
            cons[i]=c;
        }
        // for(int i=0;i<n;i++){
        //     cout<<vow[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<cons[i]<<" ";
        // }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool isvow=0;
                int vmid=vow[j]-vow[i];
                int cmid=cons[j]-cons[i];
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                    vmid++;
                }
                else{
                    cmid++;
                }
                if(vmid==cmid&&(vmid*cmid)%k==0){
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};