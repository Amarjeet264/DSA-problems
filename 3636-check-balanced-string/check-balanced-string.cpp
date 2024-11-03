class Solution {
public:
    bool isBalanced(string num) {
        int sumo = 0;
        int sume = 0;
        for(int i=0;i<num.size();i++){
            if(i%2)sumo += (num[i]-'0');
            else sume += (num[i]-'0');
        }
        return sumo==sume;
    }
};