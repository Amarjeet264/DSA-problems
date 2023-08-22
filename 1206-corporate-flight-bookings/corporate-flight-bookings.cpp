class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>v(n+1,0);
        for(auto it:bookings){
            v[it[0]]+=it[2];
            if(it[1]+1<=n)
              v[it[1]+1]-=it[2];
        }
        int sum=0;
        for(int i=1;i<n+1;i++){
            sum+=v[i];
            v[i-1]=sum;
        }
        v.pop_back();
        return v;
    }
};