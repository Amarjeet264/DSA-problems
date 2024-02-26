class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int video(int i,vector<vector<int>>& clips,int prev,int time,vector<vector<int>>&dp){
        if(prev!=clips.size()&&clips[prev][1]>=time){
            // cout<<i<<" "<<clips[prev][1]<<" ";
            return 0;
        }
        if(i>=clips.size()){
            // cout<<i<<" ";
            return 1e7;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int nottake=video(i+1,clips,prev,time,dp);
        int take=1e7;
        if(prev==clips.size()&&clips[i][0]==0){
            // cout<<i<<" "<<prev<<endl;
            take=1+video(i+1,clips,i,time,dp);
        }
        else if(prev!=clips.size()&&(clips[prev][1]>=clips[i][0]&&clips[prev][1]<=clips[i][1])){
            // cout<<i<<" "<<prev<<endl;
            take=1+video(i+1,clips,i,time,dp);
        }
        return dp[i][prev]= min(take,nottake);
    }
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end(),comp);
        vector<vector<int>>dp(clips.size(),vector<int>(clips.size()+1,-1));
        int x=video(0,clips,clips.size(),time,dp);
        return x>=1e7?-1:x;
    }
};