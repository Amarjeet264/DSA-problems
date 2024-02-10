class Solution {
public:
    int addMinimum(string word) {
        stack<char>st;
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
                if(word[i]=='a'){
                    st.push('a');
                }
                else{
                    if(word[i]=='b'){
                        cnt++;
                        st.push('b');
                    }
                    else{
                        cnt+=2;
                        st.push('c');
                    }
                }
            }
            else{
                if(word[i]=='a'){
                    if(st.top()=='b'){
                        cnt++;
                        st.push('a');
                    }
                    else if(st.top()=='c'){
                        st.push('a');
                    }
                    else{
                        cnt+=2;
                        st.push('a');
                    }
                }
                else if(word[i]=='b'){
                    if(st.top()=='c'){
                        cnt++;
                    }
                    else if(st.top()=='b'){
                        cnt+=2;
                    }
                    st.push('b');
                }
                else{
                    if(st.top()=='a'){
                        cnt++;
                    }
                    else if(st.top()=='c'){
                        cnt+=2;
                    }
                    st.push('c');
                }
            }
        }
        if(st.top()=='b'){
            cnt++;
        }
        else if(st.top()=='a'){
            cnt+=2;
        }
        return cnt;
    }
};