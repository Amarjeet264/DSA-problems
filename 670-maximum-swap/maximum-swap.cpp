class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int>pre(s.size());
        int maxi = 0;
        for(int i=s.size()-1;i>=0;i--){
            maxi = max(maxi,s[i]-'0');
            pre[i] = maxi;
        }
        int ele = -1;
        int at = -1;
        for(int i = 0;i<s.size();i++){
            if(pre[i]>s[i]-'0'){
                ele = pre[i];
                at = s[i]-'0';
                s[i] = pre[i]+'0';
                break;
            }
        }
        // cout<<ele<<" "<<at<<endl;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]-'0'==ele){
                s[i] = at+'0';
                break;
            }
        }
        // cout<<s<<endl;
        // return -1;
        return stoi(s);
    }
};