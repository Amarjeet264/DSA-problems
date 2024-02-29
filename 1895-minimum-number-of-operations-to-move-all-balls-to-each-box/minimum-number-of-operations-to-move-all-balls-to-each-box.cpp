class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        for(int i=0;i<boxes.size();i++){
            int final=0;
            int cnt=0;
            for(int j=i+1;j<boxes.size();j++){
                cnt++;
                if(boxes[j]=='1'){
                    final+=cnt;
                }
            }
            // if(i==3){
            //     cout<<final<<" "<<cnt<<;
            // }
            cnt=0;
            for(int j=i-1;j>=0;j--){
                cnt++;
                if(boxes[j]=='1'){
                    final+=cnt;
                }
            }
            ans.push_back(final);
        }
        return ans;
    }
};