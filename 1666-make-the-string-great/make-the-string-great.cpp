class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if((st.top()>='a'&&st.top()<='z'&&s[i]>='A'&&s[i]<='Z'&&st.top()==tolower(s[i]))||
                (st.top()>='A'&&st.top()<='Z'&&s[i]>='a'&&s[i]<='z'&&st.top()==toupper(s[i]))){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};