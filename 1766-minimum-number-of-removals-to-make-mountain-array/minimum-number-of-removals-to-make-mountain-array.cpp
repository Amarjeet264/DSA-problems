class Solution {
public:
    int minimumMountainRemovals(vector<int>& obstacles) {
        vector<int>ans(obstacles.size(),1);
        vector<int>dup;
        dup.push_back(obstacles[0]);
        for(int i=1;i<obstacles.size();i++){
            if(obstacles[i]>dup[dup.size()-1]){
                dup.push_back(obstacles[i]);
                ans[i]=dup.size();
            }
            else{
                int x=lower_bound(dup.begin(),dup.end(),obstacles[i])-dup.begin();
                dup[x]=obstacles[i];
                ans[i]=x+1;
            }
        }

        vector<int>ans1(obstacles.size(),1);
        vector<int>dup1;
        dup1.push_back(obstacles[obstacles.size()-1]);
        for(int i=obstacles.size()-2;i>=0;i--){
            if(obstacles[i]>dup1[dup1.size()-1]){
                dup1.push_back(obstacles[i]);
                ans1[i]=dup1.size();
            }else{
                int x=lower_bound(dup1.begin(),dup1.end(),obstacles[i])-dup1.begin();
                dup1[x]=obstacles[i];
                ans1[i]=x+1;
            }
        }
        int f=INT_MAX;
        for(int i=0;i<obstacles.size();i++){
            if(ans[i]>1&&ans1[i]>1)
            {
                int x=obstacles.size()-(ans[i]+ans1[i])+1;
                if(x<f){
                    f=x;
                }
            }
        }
        return f;
    }
};