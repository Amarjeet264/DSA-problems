class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool>x(3,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<triplets.size();j++){
                if(triplets[j][i]==target[i]&&triplets[j][(i+1)%3]<=target[(i+1)%3]&&triplets[j][(i+2)%3]<=target[(i+2)%3]){
                    x[i]=1;
                }
            }
        }
        for(int i=0;i<3;i++){
            if(!x[i]){
                return 0;
            }
        }
        return 1;
    }
};