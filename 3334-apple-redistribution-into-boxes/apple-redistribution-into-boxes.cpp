class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(apple.begin(),apple.end());
        sort(capacity.begin(),capacity.end());
        int sum=0;
        for(auto it:apple){
            sum+=it;
        }
        int cap=0;
        int cnt=0;
        int i=capacity.size()-1;
        while(cap<sum){
            cap+=capacity[i];
            cnt++;
            i--;
        }
        return cnt;
    }
};