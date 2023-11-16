class Solution {
    string ans="";
    bool find(unordered_set<string>st,int n){
        if(ans.length()==n){
            if(st.find(ans)==st.end()){
                return true;
            }
            return false;
        }
        ans+='0';
        if(find(st,n)){
            return true;
        }
        else{
            ans.pop_back();
        }
        ans+='1';
        if(find(st,n)){
            return true;
        }
        else{
            ans.pop_back();
        }
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        find(st,nums[0].size());
        return ans;
    }
};