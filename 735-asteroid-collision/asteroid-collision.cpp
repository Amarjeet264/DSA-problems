class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        for(int i=0;i<ast.size();i++){
            if(st.empty()){
                cout<<i<<"fi"<<endl;
                st.push(ast[i]);
            }
            else{
                if(ast[i]<0&&st.top()>0){
                    while(!st.empty()&&st.top()<abs(ast[i])&&st.top()>0){
                        cout<<"vvv"<<endl;
                        st.pop();
                    }
                    if(!st.empty()&&st.top()==abs(ast[i])){
                        st.pop();
                        continue;
                    }
                    if(st.empty()){
                        st.push(ast[i]);
                    }
                    else{
                        if(st.top()>0){
                            continue;
                        }
                        else if(st.top()<0){
                            st.push(ast[i]);
                        }
                    }
                }
                else{
                    cout<<i<<"li"<<endl;
                    st.push(ast[i]);
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};