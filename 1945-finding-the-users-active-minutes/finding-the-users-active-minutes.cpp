class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(),logs.end(),comp);
        vector<int>ans(k,0);
        int cnt=1;
        for(int i=1;i<logs.size();i++){
            // cout<<logs[i][0]<<" "<<logs[i][1]<<endl;
            if(logs[i][0]==logs[i-1][0]){
                if(logs[i][1]!=logs[i-1][1]){
                    cnt++;
                }
            }
            else{
                ans[cnt-1]++;
                cnt=1;
            }
            // cout<<cnt<<" ";
        }
        ans[cnt-1]++;
        return ans;
    }
};