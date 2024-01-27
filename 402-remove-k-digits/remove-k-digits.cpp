class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.length();i++){
            while(k>0&&!st.empty()&&st.top()>num[i]){
                st.pop();
                k--;
            }
            if(st.empty()&&num[i]=='0'){
                continue;
            }
            st.push(num[i]);
        }
        while(k!=0&&!st.empty()){
            st.pop();
            k--;
        }
        // while(!st.em)
        string ans="";
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            ans+=ch;
        }
        while(ans.size()>0&&ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0){
            return "0";
        }
        return ans;
    }
};