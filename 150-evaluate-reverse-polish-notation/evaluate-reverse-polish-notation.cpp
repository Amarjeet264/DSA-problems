class Solution {
    int func(int x,int y,string s){
        if(s=="+"){
            return x+y;
        }
        else if(s=="-"){
            return x-y;
        }
        else if(s=="/"){
            return x/y;
        }
        else return x*y;
    }
public:
    int evalRPN(vector<string>&s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=="+"||s[i]=="-"||s[i]=="*"||s[i]=="/"){
                int y=st.top();
                st.pop();
                int x=st.top();
                st.pop();
                st.push(func(x,y,s[i]));
            }
            else{
                st.push(stoi(s[i]));
            }
        }
        return st.top();
    }
};