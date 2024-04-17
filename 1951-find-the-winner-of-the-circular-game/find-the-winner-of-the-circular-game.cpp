class Solution {
    int ans=-1;
    void rec(vector<int>&vec,int k,int i){
        if(vec.size()==1){
            ans=vec[0];
            return;
        }
        int idx=(i+k)%vec.size();
        vec.erase(vec.begin()+idx);
        rec(vec,k,idx);
    }
public:
    int findTheWinner(int n, int k) {
        vector<int>vec(n,0);
        int cnt=1;
        for(int i=0;i<n;i++){
            vec[i]=cnt++;
        }
        k-=1;
        rec(vec,k,0);
        return ans;
    }
};