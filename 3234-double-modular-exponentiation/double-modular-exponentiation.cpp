class Solution {
    bool check(int target,vector<int>&var){
        long long x=1;
        while(var[1]--){
            x=x*var[0];
            x=x%10;
        }
        // x=x%10;
        long long z=x;
        // x=1;
        // long long mod=1e;
        if(var[2]==0){
            x=1;
        }
        while(var[2]>1){
            x=x*z;
            // cout<<z<<" "<<x<<endl;
            x=x%var[3];
            var[2]-=1;
            // x=x%mod;
        }
        x=x%var[3];
        return x==target;
    }
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int>ans;
        for(int i=0;i<variables.size();i++){
            if(check(target,variables[i])){
                ans.push_back(i);
            }
        }
        return ans;
    }
};