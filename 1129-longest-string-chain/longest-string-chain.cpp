class Solution {
    public:
    bool check(string &tar,string&start){
        if(start.length()>=tar.length()||start.length()<tar.length()-1){
            return false;
        }
        bool x=true;
        int low=0;
        int high=0;
        int count=0;
        while(low<start.length()&&high<tar.length()){
            if(start[low]==tar[high]){
                low++;
                high++;
            }
            else{
                count++;
                high++;
                if(count==2){
                    return false;
                }
            }
        }
        if(low==start.length()){
            return true;
        }
        // if(count==1&&high==tar.length()){
        //     return true;
        // }
        return false;
    }
struct cmp {
    bool operator()(string& a, string& b) {
        return a.size() < b.size();
    }
};
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        sort(words.begin(), words.end(), cmp());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])&&dp[i]<=dp[j]){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};