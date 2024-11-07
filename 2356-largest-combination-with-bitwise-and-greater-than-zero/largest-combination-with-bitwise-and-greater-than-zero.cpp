class Solution {
public:
    int largestCombination(vector<int>& can) {
        vector<int>chk(32,0);
        for(int i=0;i<can.size();i++){
            for(int j=0;j<32;j++){
                if((can[i]>>j)&1){
                    chk[j]++;
                }
            }
        }
        int maxi = 0;
        for(int i=0;i<32;i++){
            maxi = max(maxi,chk[i]);
        }
        return maxi;
    }
};