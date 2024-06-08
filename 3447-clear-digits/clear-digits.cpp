class Solution {
public:
    string clearDigits(string s) {
        int n=s.length();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!isdigit(s[i])){
                st.push(i);
                cout<<i<<" ";
            }
            else{
                if(!st.empty()){
                    s[st.top()]='#';
                    st.pop();
                }
                s[i]='#';
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='#'){
                ans+=s[i];
            }
        }
        return ans;
    }
};