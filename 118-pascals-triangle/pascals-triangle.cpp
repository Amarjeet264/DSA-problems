class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>prev;
        for(int i=0;i<numRows;i++){
            vector<int>dup;
            if(i==0){
                dup.push_back(1);
            }
            else if(i==1){
                dup.push_back(1);
                dup.push_back(1);
            }
           else{ 
               prev=ans[ans.size()-1];
               dup.push_back(1);
                for(int j=0;j<prev.size()-1;j++){
                    dup.push_back(prev[j]+prev[j+1]);
                }
                dup.push_back(1);
           }
          ans.push_back(dup);
        }
        return ans;
    }
};