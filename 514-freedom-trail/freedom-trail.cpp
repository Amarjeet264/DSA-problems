class Solution {
    int find(int i, string &key, string &ring, int curridx,vector<vector<int>>&dp) {
        if (i >= key.size()) {
            return 0;
        }
        int fr=INT_MAX;
        int bac=INT_MAX;
        int steps =0;
        int j=curridx;
        if(dp[i][curridx]!=-1){
            return dp[i][curridx];
        }
        while(ring[j]!=key[i]) {
            j=(j+1)%ring.size();
            steps++;
        }
        fr=steps+find(i + 1,key,ring,j,dp) + 1;
        steps = 0;
        j=curridx;
        while(ring[j]!=key[i]) {
            j =(j-1+ring.size())%ring.size();
            steps++;
        }
        // cout<<j<<" ";
        bac=steps+find(i + 1,key,ring,j,dp)+1;
        return dp[i][curridx]= min(fr,bac);
    }

public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(key.size(),vector<int>(ring.size(),-1));
        return find(0, key, ring, 0,dp);
    }
};
