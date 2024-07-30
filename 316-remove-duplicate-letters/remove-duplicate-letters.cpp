class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        stack<char>st;
        unordered_map<char,int>taken;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
                taken[s[i]]++;
            }
            else{
                if(taken.find(s[i])!=taken.end()){
                    continue;
                }
                else if(s[i]>st.top()){
                    st.push(s[i]);
                    taken[s[i]]++;
                }
                else{
                    if(mp[st.top()]<i){
                        st.push(s[i]);
                    }
                    else{
                        while(!st.empty()&&mp[st.top()]>i&&st.top()>s[i]){
                            taken.erase(st.top());
                            st.pop();
                        }
                        st.push(s[i]);
                    }
                    taken[s[i]]++;
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};