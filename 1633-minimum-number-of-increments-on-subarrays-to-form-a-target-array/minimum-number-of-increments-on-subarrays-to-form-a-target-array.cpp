class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        long long prev = 0;
        long long cnt = 0;
        for(int i=0;i<target.size();i++){
            long long curr = target[i];
            if(curr>prev){
                cnt+=(curr-prev);
            }
            prev = curr;
        }
        return cnt;
    }
};