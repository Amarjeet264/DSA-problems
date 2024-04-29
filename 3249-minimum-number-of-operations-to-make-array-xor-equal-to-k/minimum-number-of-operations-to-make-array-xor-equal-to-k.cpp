class Solution {
    void con(int x,string &s){
        while(x){
            if(x%2==0){
                s+='0';
            }
            else{
                s+='1';
            }
            x=x/2;
        }
        reverse(s.begin(),s.end());
    }
public:
    int minOperations(vector<int>& nums, int k) {
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
            x=x^nums[i];
        }
        string s="";
        con(x,s);
        string z="";
        con(k,z);
        // cout<<s<<" ";
        int cnt=0;
        int sz=s.size();
        int i=0;
        reverse(z.begin(),z.end());
        while(s.size()>z.size()){
            z+='0';
        }
        reverse(z.begin(),z.end());
        // int i=0;

        reverse(s.begin(),s.end());
        while(s.size()<z.size()){
            s+='0';
        }
        reverse(s.begin(),s.end());

        while(i<s.size()){
            if(s[i]!=z[i]){
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};