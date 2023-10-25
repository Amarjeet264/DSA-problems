class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int idx=-1;
        int def=0;
        int abhi=0;
        for(int i=0;i<n;i++){
            if(abhi+gas[i]<cost[i]){
                def+=abs(abhi+gas[i]-cost[i]);
                abhi=0;
                idx=-1;
            }
            else{
                abhi+=(gas[i]-cost[i]);
                if(idx==-1)idx=i;
            }
        }
        if(abhi>=def)return idx;
        return -1;
    }
};