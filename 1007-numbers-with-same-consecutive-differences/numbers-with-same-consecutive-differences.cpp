class Solution {
    vector<int>ans;
    void count(int curr,int n,int k){
        if(to_string(curr).length()==n){
            ans.push_back(curr);
            return;
        }
        // cout<<curr<<" ";
        for(int i=0;i<=9;i++){
            if(curr==0){
                if(i!=0){
                    count(curr*10+i,n,k);
                }
                else continue;
            }
            else{
                int prev=curr%10;
                if(abs(i-prev)==k){
                    count(curr*10+i,n,k);
                }
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        count(0,n,k);
        return ans;
    }
};