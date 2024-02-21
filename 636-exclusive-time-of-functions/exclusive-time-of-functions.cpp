class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int,int>>st;
        vector<int>ans(n,0);
        int prev=0;
        for(auto s:logs){
            int id=stoi(s.substr(0,s.find(':')));
            int time=stoi(s.substr(s.rfind(':')+1,s.length()));
            if(s.find('e')!=-1){
                ans[id]+=time-prev+1;
                st.pop();
                prev=time+1;
            }
            else{
                if(!st.empty()){
                    ans[st.top().first]+=time-prev;
                }
                st.push({id,time});
                prev=time;
            }
        }
        return ans;
    }
};