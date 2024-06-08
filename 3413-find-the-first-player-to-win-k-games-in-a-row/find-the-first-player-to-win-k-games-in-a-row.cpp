class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        if(k>=skills.size()){
            int maxi=0;
            for(int i=1;i<skills.size();i++){
                if(skills[maxi]<skills[i]){
                    maxi=i;
                }
            }
            return maxi;
        }
        int winner=0;
        int cnt=0;
        for(int i=1;i<skills.size();i++){
            if(skills[i]<skills[winner]){
                cnt++;
            }
            else{
                winner=i;
                cnt=1;
            }
            if(cnt==k){
                return winner;
            }
        }
        return winner;
    }
};