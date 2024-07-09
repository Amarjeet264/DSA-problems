class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>to(n+1);
        for(int i=0;i<ranges.size();i++){
            int left = max(0,i-ranges[i]);
            int right = min(n,i+ranges[i]);
            to[left] = max(to[left],right);
        }
        int currend = to[0];
        int maxend = to[0];
        int taps = 1;
        for(int i=1;i<=n;i++){
            if(i>maxend){
                return -1;
            }
            if(i>currend){
                taps++;
                currend = maxend;
            }
            maxend = max(maxend,to[i]);
        }
        return taps;
    }
};