class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>vec;
        int xo = 0;
        for(int i=0;i<arr.size();i++){
            xo = xo^arr[i];
            vec.push_back(xo);
        }
        vector<int>ans;
        for(int i =0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(left-1>=0){
                ans.push_back(vec[right]^vec[left-1]);
            }
            else{
                ans.push_back(vec[right]);
            }
        }
        return ans;
    }
};