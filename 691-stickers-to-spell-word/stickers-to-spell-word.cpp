class Solution {
    int stick(vector<vector<int>>&vec,map<string,int>&dp,string tar){
        if(tar==""){
            return 0;
        }
        if(dp.find(tar)!=dp.end()){
            return dp[tar];
        }
        vector<int>freq(26);
        int take=1e9;
        for(int i=0;i<vec.size();i++){
            // if(vec[i][tar[0]-'a']==0)continue;
            bool ha=false;
            freq=vec[i];
            string rem="";
            for(int k=0;k<tar.size();k++){
                if(freq[tar[k]-'a']>0){
                    freq[tar[k]-'a']--;
                    ha=true;
                }
                else{
                    rem+=tar[k];
                }
            }
            if(!ha)continue;
            take=min(take,1+stick(vec,dp,rem));
        }
        return dp[tar]= take;
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>>vec(stickers.size(),vector<int>(26,0));
        for(int i=0;i<stickers.size();i++){
            for(int j=0;j<stickers[i].size();j++){
                vec[i][stickers[i][j]-'a']++;
            }
        }
        map<string,int>dp;
        int x=stick(vec,dp,target);
        return x>=1e5?-1:x;
    }
};