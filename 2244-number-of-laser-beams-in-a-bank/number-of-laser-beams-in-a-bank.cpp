class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>ans;
        int n=bank.size();
        for(int i=0;i<n;i++){
            string s=bank[i];
            int cnt=0;
            for(int j=0;j<s.length();j++){
                if(s[j]=='1'){
                    cnt++;
                }
            }
            if(cnt!=0)
            ans.push_back(cnt);
        }
        if(ans.size()<=1){
            return 0;
        }
        int prev=ans[0];
        // cout<<prev<<" ";
        int res=0;
        for(int i=1;i<ans.size();i++){
            // cout<<ans[i]<<" ";
            res=res+ans[i]*prev;
            prev=ans[i];
        }
        return res;
    }
};