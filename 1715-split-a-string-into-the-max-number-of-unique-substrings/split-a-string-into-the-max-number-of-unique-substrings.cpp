class Solution {
    int maxi = 1;
    int call(int i,string s ,unordered_set<string>&st){
        if(i>=s.size()){
            return 0;
        }
        string str = "";
        int maxi = 0;
        for(int j = i;j<s.size();j++){
            str+=s[j];
            if(st.find(str)==st.end()){
                st.insert(str);
                maxi = max(maxi,1+call(j+1,s,st));
                st.erase(str);
            }
        }
        return maxi;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        return call(0,s,st);
        // return maxi;
    }
};