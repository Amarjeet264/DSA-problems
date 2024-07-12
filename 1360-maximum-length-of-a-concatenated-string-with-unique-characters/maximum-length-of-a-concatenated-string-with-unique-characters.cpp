class Solution {
    int calc(vector<int>&vec,int i,int temp){
        if(i>=vec.size()){
            return __builtin_popcount(temp);
        }
        int nottake = calc(vec,i+1,temp);
        int take = 0;
        if((temp&vec[i])==0){
            take = calc(vec,i+1,temp|vec[i]);
        }
        return max(take,nottake);
    }
public:
    int maxLength(vector<string>& arr) {
        vector<int>vec;
        for(int i=0;i<arr.size();i++){
            string s = arr[i];
            unordered_set<char>st;
            for(int j=0;j<s.size();j++){
                st.insert(s[j]);
            }
            if(st.size()!=s.size()){
                continue;
            }
            int val = 0;
            for(int j=0;j<arr[i].size();j++){
                int n = arr[i][j]-'a';
                val = val|(1<<n);
            }
            vec.push_back(val);
        }
        int temp = 0;
        return calc(vec,0,temp);
    }
};