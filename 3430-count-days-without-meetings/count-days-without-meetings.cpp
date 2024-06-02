class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>temp;
        temp.push_back(meetings[0]);
        for(int i=1;i<meetings.size();i++){
            vector<int>dup=temp.back();
            temp.pop_back();
            if(meetings[i][0]<=dup[1]){
                temp.push_back({dup[0],max(dup[1],meetings[i][1])});
            }
            else{
                temp.push_back(dup);
                temp.push_back(meetings[i]);
            }
        }
        for(int i=0;i<temp.size();i++){
            days-=(temp[i][1]-temp[i][0]+1);
        }
        return days;
    }
};