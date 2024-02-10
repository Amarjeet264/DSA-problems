class Solution {
    int calc(string s,stack<char>&st,int add,char first,char second){
        int score=0;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top()==first&&s[i]==second){
                    score+=add;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        return score;
    }
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>y){
            stack<char>st;
            ans+=calc(s,st,x,'a','b');
            string str="";
            while(!st.empty()){
                str+=st.top();
                st.pop();
            }
            reverse(str.begin(),str.end());
            ans+=calc(str,st,y,'b','a');
        }
        else{
            stack<char>st;
            ans+=calc(s,st,y,'b','a');
            string str="";
            while(!st.empty()){
                str+=st.top();
                st.pop();
            }
            reverse(str.begin(),str.end());
            ans+=calc(str,st,x,'a','b');
        }
        return ans;
    }
};