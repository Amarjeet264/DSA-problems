class Solution {
    unordered_map<char,bool>mp;
    bool isop(char ch){
        if(ch=='&'||ch=='|'||ch=='!'||ch=='('){
            return 1;
        }
        return 0;
    }
    bool eval(string s,char ch){
        bool ans = true;
        if(ch=='&'){
            for(int i=0;i<s.size();i++){
                ans = ans & mp[s[i]];
            }
            return ans;
        }
        else if(ch=='|'){
            ans = false;
             for(int i=0;i<s.size();i++){
                ans = ans | mp[s[i]];
            }
            return ans;
        }
        else return s[0]=='t'?false:true;
        // return !ans;
    }
public:
    bool parseBoolExpr(string exp) {
        mp['t'] = true;
        mp['f'] = false;
        stack<char>st;
        for(int i = 0;i<exp.size();i++){
            if(isop(exp[i])||exp[i]=='t'||exp[i]=='f'){
                st.push(exp[i]);
                cout<<i<<" "<<exp[i]<<endl;
            }
            else if(exp[i]==',')continue;
            else{
                string s = "";
                while(!st.empty()&&!isop(st.top())){
                    s += st.top();
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                bool x = eval(s,op);
                cout<<s<<" "<<op<<" "<<x<<endl;
                st.push(x==true?'t':'f');
            }
        }
        return st.top()=='t'?true:false;
    }
};