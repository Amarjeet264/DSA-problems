class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int j=tokens.size()-1;
        int i=0;
        int curr=power;
        int maxi=0;
        int score=0;
        while(i<=j){
            if(curr>=tokens[i]){
                curr-=tokens[i];
                score++;
                i++;
            }
            else{
                if(score>0){
                    curr+=tokens[j];
                    score--;
                    j--;
                }
                else{
                    break;
                }
            }
            maxi=max(maxi,score);
        }
        return maxi;
    }
};