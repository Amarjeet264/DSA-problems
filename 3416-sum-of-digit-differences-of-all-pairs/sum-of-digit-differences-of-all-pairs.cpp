class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int total=0;
        int a=nums[0];
        while(a){
            a=a/10;
            total++;
        }
        vector<vector<int>>vec(total,vector<int>(10,0));
        for(auto it:nums){
            string s=to_string(it);
            for(int i=0;i<s.length();i++){
                vec[i][s[i]-'0']++;
            }
        }
        long long ans=0;
        for(int i=0;i<total;i++){
            int x=nums.size();
            for(int j=0;j<10;j++){
                for(int k = j+1; k < 10; k++) {
                    ans += (vec[i][j]*vec[i][k]);
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};