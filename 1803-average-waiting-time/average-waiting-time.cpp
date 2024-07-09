class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int time = 0;
        for(int i=0;i<customers.size();i++){
            if(time>customers[i][0]){
                ans += (time-customers[i][0]);
                time += customers[i][1];
            }
            else{
                time = customers[i][0] + customers[i][1];
            }
            ans += customers[i][1];
        }
        return ans/customers.size();
    }
};