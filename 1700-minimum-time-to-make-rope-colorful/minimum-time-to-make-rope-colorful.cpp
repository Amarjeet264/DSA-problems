class Solution {
public:
    int minCost(string colors, vector<int>& need) {
        int i=0;
        int j=1;
        int sum=0;

        while(j<colors.size()){
            if(colors[i]==colors[j]){
                if(need[i]<need[j]){
                    sum+=need[i];
                    i=j;
                    j++;
                }
                else{
                    sum+=need[j];
                    j++;
                }
            }
            else{
                i=j;
                j++;
            }
        }
        return sum;
    }
};