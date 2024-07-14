class Solution {
public:
    int minCost(string colors, vector<int>& need) {
        int j=1;
        int time=0;
        int prevMax = need[0];
        while(j<colors.size()){
            if(colors[j]!=colors[j-1]){
                prevMax = 0;
            }
            time += min(prevMax,need[j]);
            prevMax = max(prevMax,need[j]);
            j++;
        }
        return time;
    }
};