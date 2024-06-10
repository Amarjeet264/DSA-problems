class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>x=heights;
        sort(heights.begin(),heights.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=x[i]){
                cnt++;
            }
        }
        return cnt;
    }
};