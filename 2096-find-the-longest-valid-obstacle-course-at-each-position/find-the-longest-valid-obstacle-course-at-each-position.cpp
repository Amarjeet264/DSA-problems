class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>ans(obstacles.size(),1);
        vector<int>dup;
        dup.push_back(obstacles[0]);
        for(int i=1;i<obstacles.size();i++){
            if(obstacles[i]>=dup[dup.size()-1]){
                dup.push_back(obstacles[i]);
                ans[i]=dup.size();
            }
            else{
                int x=upper_bound(dup.begin(),dup.end(),obstacles[i])-dup.begin();
                dup[x]=obstacles[i];
                ans[i]=x+1;
            }
        }
        return ans;
    }
};