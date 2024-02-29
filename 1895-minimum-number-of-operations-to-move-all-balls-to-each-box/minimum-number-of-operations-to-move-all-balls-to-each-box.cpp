class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        // for(int i=0;i<boxes.size();i++){
            int final=0;
            int cnt=0;
            for(int j=0;j<boxes.size();j++){
                ans.push_back(final);
                if(boxes[j]=='1'){
                    cnt++;
                }
                    final+=cnt;
            }
            cnt=0;
            final=0;
            for(int j=boxes.size()-1;j>=0;j--){
                ans[j]+=final;
                if(boxes[j]=='1'){
                    cnt++;
                }
                final+=cnt;
            }
            // ans.push_back(final);
        // }
        return ans;
    }
};