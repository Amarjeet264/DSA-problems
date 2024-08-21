class Solution {
    int strange(int left,int right,string s,vector<vector<int>>&dp){
        if(left==right){
            return 1;
        }
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int i = left+1;
        while(i<=right&&s[left]==s[i]){
            i++;
        }
        if(i>right)return 1;
        int one = 1 + strange(i,right,s,dp);
        int gre = INT_MAX;
        for(int j=i;j<=right;j++){
            if(s[j]==s[left]){
                int x = strange(j,right,s,dp)+strange(i,j-1,s,dp);
                gre = min(gre,x);
            }
        }
        return dp[left][right] =  min(gre,one);
    }
public:
    int strangePrinter(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return strange(0,s.size()-1,s,dp);
    }
};