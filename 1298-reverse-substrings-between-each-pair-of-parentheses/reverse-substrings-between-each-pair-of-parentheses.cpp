class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        int n=s.length();
        string x="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                string ans="";
                while(!st.empty()&&st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
                for(int i=0;i<ans.size();i++){
                    st.push(ans[i]);
                }
            }
        }
        while(!st.empty()){
            x+=st.top();
            st.pop();
        }
        reverse(x.begin(),x.end());
        return x;
    }
};