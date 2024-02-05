class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int> s;
        int i,j,n = arr.size(),l,ans = 0,x,y,z;
        for(auto &i: arr){
            s.insert(i);
        }
        for(i = 0; i < n; i++){
            for(j = i+1; j < n; j++){
                x = arr[i], y = arr[j],l = 2;
                while(s.count(x+y)){
                    l++;
                    z = x+y;
                    x = y;
                    y = z;
                }
                ans = max(ans,l);
            }
        }
        return ans>2?ans:0;
    }
};