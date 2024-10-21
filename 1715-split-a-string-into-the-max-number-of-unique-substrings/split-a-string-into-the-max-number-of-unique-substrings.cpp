class Solution {
    int maxi = 1;
    void call(int i,string s ,unordered_set<string>st,int cnt){
        if(i>=s.size()){
            maxi = max(maxi,cnt);
            return;
        }
        string str = "";
        for(int j = i;j<s.size();j++){
            str+=s[j];
            if(st.find(str)==st.end()){
                st.insert(str);
                call(j+1,s,st,cnt+1);
                st.erase(str);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        call(0,s,st,0);
        return maxi;
    }
};