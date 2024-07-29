class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int lim = sqrt(r);
        vector<int>v(lim+1,1);
        v[0] = 0;
        v[1] = 0;
        for(int i = 2;i*i<=lim;i++){
            if(v[i]){
                for(int j = i*i;j<=lim;j+=i){
                    v[j] = 0;
                }
            }
        }
        int cnt = 0;
        for(int i = 2;i<=lim;i++){
            if(v[i]){
                int sq = i*i;
                if(sq>=l&&sq<=r){
                    cnt++;
                }
            }
        }
        int total = r-l+1;
        return total - cnt;
    }
};