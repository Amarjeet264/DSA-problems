class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int one=player1[0];
        int sec=player2[0];
        for(int i=0;i<player1.size();i++){
            if(i>=2){
                if(player1[i-1]==10||player1[i-2]==10){
                    one+=(2*player1[i]);
                }
                else{
                    one+=player1[i];
                }
            }
            else if(i>=1){
                if(player1[i-1]==10){
                    one+=(2*player1[i]);
                }
                else{
                    one+=player1[i];
                }
            }
            if(i>=2){
                if(player2[i-1]==10||player2[i-2]==10){
                    sec+=(2*player2[i]);
                }
                else{
                    sec+=player2[i];
                }
            }
            else if(i>=1){
                if(player2[i-1]==10){
                    sec+=(2*player2[i]);
                }
                else{
                    sec+=player2[i];
                }
            }
        }
        // cout<<one<<" "<<sec<<endl;
        if(one>sec)return 1;
        else if(sec>one)return 2;
        return 0;
    }
};