class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newEvent) {
        vector<vector<int>>ans;
        int N=intervals.size();
        int i=0;
        while(i<N&&intervals[i][1]<newEvent[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<N&&intervals[i][0]<=newEvent[1]){
            newEvent[0]=min(newEvent[0],intervals[i][0]);
            newEvent[1]=max(newEvent[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newEvent);
        while(i<N){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};