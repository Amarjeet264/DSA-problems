class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        long long prev = 0;
        long long cnt = 0;
        for(int i=0;i<target.size();i++){
            long long curr = target[i];
            if((curr<0&&prev>0)||(curr>0&&prev<0)){
                cnt += abs(curr);
            }
            else{
                if(curr>prev){
                    cnt+=abs(curr-prev);
                }
            }
            prev = curr;
        }
        return cnt;
    }
};