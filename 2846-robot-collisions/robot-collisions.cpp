class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>>vec;
        for(int i=0;i<positions.size();i++){
            vec.push_back({positions[i],i});
        }
        sort(vec.begin(),vec.end());
        stack<int>st;
        for(int i=0;i<positions.size();i++){
            // cout<<vec[i].first<<" "<<vec[i].second<<endl;
            if(st.empty()){
                st.push(vec[i].second);
            }
            else{
                if((directions[vec[i].second]=='R'&&directions[st.top()]=='L')||(directions[vec[i].second]==directions[st.top()])){
                    st.push(vec[i].second);
                    continue;
                }
                while(!st.empty()&&directions[st.top()]!=directions[vec[i].second]&&healths[st.top()]<healths[vec[i].second]){
                    healths[st.top()]=0;
                    st.pop();
                    healths[vec[i].second]-=1;
                }
                if(!st.empty()&&directions[vec[i].second]!=directions[st.top()]&&healths[st.top()]==healths[vec[i].second]){
                    healths[st.top()]=0;
                    st.pop();
                    healths[vec[i].second]=0;
                    continue;
                }
                if(!st.empty()&&directions[vec[i].second]!=directions[st.top()]&&healths[vec[i].second]>0){
                    healths[st.top()]-=1;
                    healths[vec[i].second]=0;
                    if(healths[st.top()]==0){
                        st.pop();
                    }
                    continue;
                }
                if(healths[vec[i].second]>0)st.push(vec[i].second);
            }
        }
        vector<int>ans;
        for(int i=0;i<healths.size();i++){
            if(healths[i]>0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};