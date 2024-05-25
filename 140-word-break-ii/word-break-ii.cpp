class Solution {
    vector<string>ans;
    set<string>st;
    void find(int idx,string temp,string s){
        if(idx>=s.length()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(st.count(s.substr(idx,i-idx+1))){
                find(i+1,temp+s.substr(idx,i-idx+1)+" ",s);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& word) {
        for(int i=0;i<word.size();i++){
            st.insert(word[i]);
        }
        find(0,"",s);
        return ans;
    }
};