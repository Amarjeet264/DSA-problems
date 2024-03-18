class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int i=0;
        int cnt=0;
        while(i<points.size()){
            int abhi=points[i][1];
            int j=i+1;
            int mini=abhi;
            while(j<points.size()&&points[j][0]<=mini){
                mini=min(mini,points[j][1]);
                j++;
            }
            cnt++;
            i=j;
        }
        return cnt;
    }
};