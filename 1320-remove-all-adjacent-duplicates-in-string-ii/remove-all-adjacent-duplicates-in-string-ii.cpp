class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(!st.empty()&&s[i]==st.top().first){
                int now=1+st.top().second;
                st.pop();
                st.push({s[i],now});
                if(now==k){
                    st.pop();
                }
            }
            else{
                st.push({s[i],1});
            }
        }
        string ans="";
        while(!st.empty()){
            int cnt=st.top().second;
            char c=st.top().first;
            st.pop();
            while(cnt--){
                ans+=c;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};