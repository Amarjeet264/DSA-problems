class Solution {
    int convert(string &s){
        int h=stoi(s.substr(0,2));
        int m=stoi(s.substr(3,4));
        return h*60+m;
    }
public:
    int findMinDifference(vector<string>& time) {
        vector<int>minu;
        for(auto it:time){
            minu.push_back(convert(it));
        }
        sort(minu.begin(),minu.end());
        int mini=INT_MAX;
        for(int i=0;i<minu.size()-1;i++){
            mini=min(mini,minu[i+1]-minu[i]);
        }
        int circle=minu[0]+1440-minu[minu.size()-1];
        if(circle>0){
            mini=min(mini,circle);
        }
        return mini;
    }
};