class Solution {
    unordered_set<string>st;
    void letter(string s,int i){
        if(i>=s.length()){
            st.insert(s);
            return;
        }
        // cout<<s<<" ";
        letter(s,i+1);
        if(!(s[i]-'0'>=0&&s[i]-'0'<=9)){
            if(s[i]>='a'&&s[i]<='z'){
                s[i]=toupper(s[i]);
                letter(s,i+1);
            }
            else{
                s[i]=tolower(s[i]);
                letter(s,i+1);
            }
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        letter(s,0);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};