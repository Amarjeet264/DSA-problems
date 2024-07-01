class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(int i=0;i<answers.size();i++){
            mp[answers[i]]++;
        }
        int cnt=0;
        for(auto it:mp){
            int rem = it.second%(it.first+1);
            int g = it.second/(it.first+1);
            cnt+=g*(it.first+1);
            if(rem!=0){
                cnt+=(it.first+1);
            }
        }
        return cnt;
    }
};