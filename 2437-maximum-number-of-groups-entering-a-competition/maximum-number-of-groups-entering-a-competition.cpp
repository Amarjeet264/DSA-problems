class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int cnt=1;
        for(int i=0;i<grades.size();i=i+cnt){
            cnt++;
        }
        return cnt-1;
    }
};