class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n=prices.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()>prices[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(prices[i]);
            }
            else{
                ans.push_back(prices[i]-st.top());
            }
            st.push(prices[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};