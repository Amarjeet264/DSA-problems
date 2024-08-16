class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxi = 0;
        int maxEle = INT_MIN;
        int minEle = INT_MAX;
        for(int i =0;i<arrays.size();i++){
            for(int j = 0;j<arrays[i].size();j++){
                if(maxEle!=INT_MIN)maxi = max(maxi,abs(arrays[i][j]-maxEle));
                if(minEle!=INT_MAX)maxi = max(maxi,abs(arrays[i][j]-minEle));
            }
            for(int j = 0;j<arrays[i].size();j++){
                maxEle = max(maxEle,arrays[i][j]);
                minEle = min(minEle,arrays[i][j]);
            }
        }
        return maxi;
    }
};